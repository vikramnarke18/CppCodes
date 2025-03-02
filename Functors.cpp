//In C++, a functor (or function object) is an object of a class that overloads 
// the function call operator (), 
//allowing it to be invoked as if it were a regular function. This enables objects 
// to exhibit function-like behavior.

#include <iostream>  // Include the input-output stream library

using namespace std;  // Use the standard namespace

// Define a class named 'test'
class test {
public:
    int a;  // Public integer member variable

    // Overload the function call operator
    void operator()(int b) {
        a = b;  // Assign the value of 'b' to member variable 'a'
        cout << a<<endl;  // Output the value of 'a' to the console
    }
};

int main() {
    test t1;  // Create an instance 't1' of the class 'test'
    t1(2);    // Invoke the overloaded 'operator()' with the argument 2
    t1(3);    // Invoke the overloaded 'operator()' with the argument 3

    return 0;  // Indicate successful program termination
}

