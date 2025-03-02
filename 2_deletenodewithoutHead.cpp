#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Function to delete a node when head is NOT given
void deleteNodeWithoutHead(Node* node) {
    if (node == nullptr || node->next == nullptr) {
        cout << "Deletion not possible!" << endl;
        return;
    }

    // Copy data from the next node into the current node
    Node* temp = node->next;
    node->data = temp->data;
    node->next = temp->next;

    // Delete the copied node
    delete temp;
}

// Function to print the linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Example usage
int main() {
    // Creating a sample linked list: 10 -> 20 -> 30 -> 40 -> NULL
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Before deletion: ";
    display(head);

    // Delete the node containing 20 (without head access)
    deleteNodeWithoutHead(head->next);

    cout << "After deletion: ";
    display(head);

    return 0;
}

