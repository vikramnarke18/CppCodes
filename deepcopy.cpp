// Online C++ compiler to run C++ program online

//A deep copy creates a completely independent copy by allocating new memory and copying the 
// actual data, rather than just copying the pointer.
#include <iostream>
using namespace std;

class test {
public:
    string name;  // String to store the name
    int *p;       // Pointer to dynamically allocated integer

    // Constructor to initialize name and dynamically allocate memory for integer
    test(string name1, int b) {
        name = name1;    // Assigning name
        p = new int;     // Allocating memory
        *p = b;         // Storing value in allocated memory
    }

    // Copy Constructor (Deep Copy)
    test(const test &obj) {
        name = obj.name;   // Copying name
        p = new int;       // Allocating new memory for deep copy
        *p = *(obj.p);     // Copying the value from obj.p
    }

    // Function to display object data
    void display() {
        cout << name << " -> " << *p << endl;
    }

    // Destructor to release dynamically allocated memory
    ~test() {
        delete p;
    }
};

int main() {
    test t1("Vikram", 10); // Creating object t1
    test t2(t1);           // Creating object t2 using copy constructor (deep copy)
    
    t2.display();          // Displaying t2 data

    return 0;
}
