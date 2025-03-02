// Online C++ compiler to run C++ program online
//Characteristics of Shallow Copy:
/*Copies only the pointer’s address, not the actual memory content.
Both objects will point to the same dynamically allocated memory.
If one object modifies the shared memory, the changes affect the other object.
Can cause double deletion issues when both objects try to delete the same memory in their destructors.*/
#include <iostream>
using namespace std;

class test {
public:
    string name;  // String variable to store the name
    int *p;       // Pointer to dynamically allocated integer

    // Constructor to initialize name and allocate memory for integer
    test(string name1, int b) {
        name = name1;  // Assigning name
        p = new int;   // Allocating memory dynamically
        *p = b;        // Assigning value to allocated memory
    }

    // Copy Constructor (Incorrect: Does Not Allocate New Memory)
    test(const test &obj) {
        name = obj.name;  // Copy name

        // ❌ ERROR: No new memory allocation for `p`, causing shallow copy
        // *p = *(obj.p); // This would cause segmentation fault since `p` is uninitialized

        // ✅ FIX: Allocate new memory and perform deep copy
      //  p = new int;  
        *p = *(obj.p);  
    }

    // Function to display object data
    void display() {
        cout << name << " -> " << *p << endl;
    }


  
};

int main() {
    test t1("Vikram", 10); // Create object t1
    test t2(t1);           // Create object t2 using copy constructor (deep copy)
    
    t2.display();          // Display t2's data

    return 0;
}
