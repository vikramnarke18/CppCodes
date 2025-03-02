//https://www.youtube.com/watch?v=LyuuqCVkP5I
#include <iostream>
using namespace std;

// Node class representing each element in the linked list
class Node {
public:
    int data;   // Stores the data of the node
    Node* next; // Pointer to the next node in the list

    // Constructor to initialize a node with a value and set next to nullptr
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Linked list class to manage linked list operations
class Linked {
public:
    Node* head; // Pointer to the first node
    Node* tail; // Pointer to the last node

    // Constructor initializes an empty linked list
    Linked() {
        head = tail = nullptr;
    }

    // Function to insert a new node at the front of the linked list
    void pushfront(int value) {
        Node* newNode = new Node(value); // Create a new node

        // If the list is empty, newNode becomes both head and tail
        if (head == nullptr) {
            head = tail = newNode;
        
        }
        else{

        // Link newNode to the current h  ead and update head to newNode
        newNode->next = head;
        head = newNode;

        }
    }

    // Function to insert a new node at the end of the linked list
    void pushback(int value) {
        Node* newNode = new Node(value); // Create a new node

        // If the list is empty, newNode becomes both head and tail
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }

        // Append newNode at the end and update tail
        tail->next = newNode;
        tail = newNode;
    }
    
    // Function to remove the first node of the linked list
    void popfront() {
        if (head == nullptr) { // Check if the list is empty
            cout << "Linked list is empty" << endl;
            return;
        }
        
        Node* temp = head; // Store the current head
        head = temp->next; // Move head to the next node
        temp->next = nullptr; // Nullify temp before deleting
        delete temp; // Free memory
    }
    
    // Function to remove the last node of the linked list
    void popback() {
        if (head == nullptr) { // Check if the list is empty
            cout << "LL is empty" << endl;
            return;
        }

        Node* temp = head; // Start from head
        while (temp->next != tail) { // Traverse to the second last node
            temp = temp->next;
        }
        
        temp->next = nullptr; // Remove link to last node
        delete tail; // Delete last node
        tail = temp; // Update tail pointer
    }

    // Function to insert a new node at a specific position
    void insert(int value, int pos) {
        if (pos < 0) { // Invalid position check
            cout << "invalid pos" << endl;
            return;
        }
        
        if (pos == 0) { // Insert at the front
            pushfront(value);
            return;
        }
        
        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) { // Traverse to the node before the position
            temp = temp->next;
        }
        
        Node* newNode = new Node(value); // Create new node
        newNode->next = temp->next; // Link newNode to the next node
        temp->next = newNode; // Update previous node's next pointer
    }
  
    // Function to search for a value in the linked list
    int search(int value) {
        Node* temp = head;
        int index = 0;
        
        while (temp != NULL) { // Traverse the list
            if (temp->data == value) {
                return index; // Return index if value is found
            }
            temp = temp->next;
            index++;
        }
        
        return -1; // Return -1 if value is not found
    }
    
    // Function to display the linked list
    void display() {
        Node* temp = head; // Start from the head

        // Traverse the list and print each node's data
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next; // Move to the next node
        }

        cout << "NULL" << endl; // End of the list
    }
};

// Main function to test the linked list
int main() {
    Linked list; // Create a linked list object

    // Insert elements at the front
    list.pushfront(10);
    list.pushfront(20);
    list.pushfront(50);
    list.pushfront(60);
    list.pushfront(70);

    // Insert an element at the specified position (index 4)
    list.insert(40, 4);

    // Display the linked list
    list.display();
    
    // Search for an element and print its index
    cout << list.search(200) << endl;

    return 0;
}
