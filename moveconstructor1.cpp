#include <iostream>
using namespace std;

class test {
public:
    int a;   // Integer variable
    int *p;  // Pointer to dynamically allocated memory
    
    // Parameterized Constructor
    test(int c, int d) {
        a = c;
        p = new int;  // Allocate memory dynamically
        *p = d;
    }

    // Move Constructor
    test(test&& obj) noexcept { // Marked noexcept for performance optimization
        a = obj.a;  // Move value
        p = obj.p;  // Transfer ownership of the pointer

        // Nullify source object’s pointer to prevent accidental deletion
        obj.p = nullptr;
        obj.a = 0; // Reset integer value (optional)

        cout << "Move Constructor Called" << endl;
    }

    // Function to display object data
    void display() {
        if (p) {
            cout << a << " " << *p << endl;
        } else {
            cout << a << " [nullptr]" << endl;
        }
    }

    // Destructor to free memory
    ~test() {
        delete p; // Only deletes if p is not nullptr
        cout << "Destructor Called" << endl;
    }
};

int main() {
    test t1(8, 9);   // Create object t1
    test t2 = move(t1);  // Move constructor is called

    t2.display();  // Display moved object

    return 0; // Destructor will be called for t2, t1 will have nullptr
}
