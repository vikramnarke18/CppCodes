/*In C++, a friend function is a function that is not a member of a class but 
is allowed to access the private and protected members of the class. Normally,
 private and protected members of a class can only be accessed by the class's
  own member functions. However, by declaring a
 function as a friend, you give it special permission to access those private or protected members.  */
// Online C++ compiler to run C++ program online

#include <iostream> // Include the library for input/output operations
using namespace std; // Use the standard namespace to simplify code

// Define a class named `test`
class test {
private: 
    int a = 5; // Private member variable `a` initialized to 5
    int b = 6; // Private member variable `b` initialized to 6

    // Declare `display` as a friend function to grant it access to private members
    friend void display(test &obj); 

}; // End of class definition

// Define the friend function `display` to access private members of the `test` class
void display(test &obj) {
    // Access and print the private member `a` of the passed `test` object
    cout << "Display a = " << obj.a << endl;

    // Access and print the private member `b` of the passed `test` object
    cout << "Display b = " << obj.b << endl;
}

// Entry point of the program
int main() {
    // Create an object of class `test`
    test t1;

    // Call the `display` function, passing the object `t1` as an argument
    display(t1);

    // Exit the program
    return 0;
}




/*Parameter (person &p):

person: This indicates that the function expects an argument of type person.
& (Reference): The ampersand (&) signifies that p is a reference to a person object, not a copy. This means:
Any changes made to p within the display function would affect the original person object that was passed in.
Passing by reference is often more efficient than passing by value, especially for large objects, because it avoids copying the entire object.*/