#include <iostream>
using namespace std;

class A {
public:
    int x;  // Regular member variable

    // Defining a mutable variable
    mutable int y; // Can be modified even in a const object

    // Constructor initializing x and y
   
A() {
    x = 4; // Default initialized first, then assigned
    y = 10;
}

};

int main() {
    // Create a constant object
    const A a;

    // Modify the mutable variable y
    a.y = 200;  // Allowed because y is mutable
    cout << "Modified y: " << a.y << endl;

    // Uncommenting the lines below will cause a compilation error
    // because x is not mutable and cannot be modified in a const object
    /*
    a.x = 8;  // Error: cannot modify x
    cout << "Modified x: " << a.x;
    */

    return 0;
}
