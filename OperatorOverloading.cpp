#include <iostream>
using namespace std;

class complex {
public:
    int real;
    int img;

    /* Overloading + operator with reference parameter to avoid object copy*/

    complex  operator+ (const complex x) {

        complex temp;
        temp.real = real + x.real;
        temp.img = img + x.img;
       return temp;
        
    }
};

int main() {
    complex c1, c2, c3;

    c1.real = 10;
    c1.img = 15;

    c2.real = 5;
    c2.img = 7;

    c3 = c1 + c2;

    cout << c3.real << "+i" << c3.img << endl;

    return 0;


}

/*
Operator overloading in C++ is called so because it allows you to redefine or "overload" 
the behavior of built-in operators (like +, -, *, ==, etc.) to work with user-defined data types (e.g., classes and structs).

Why it's called "overloading":
Multiple meanings (Overloading concept):

Just like function overloading, where multiple functions with the same name perform different tasks based on parameters, 
operator overloading allows operators to perform different operations based on operand types.
Example: The + operator can be overloaded to work with objects, such as adding two complex numbers.
Extending built-in operator behavior:

Normally, operators work with primitive types (like int or double), but operator overloading extends their functionality to work with complex objects like string, complex, matrix, etc.
Maintains code readability and natural syntax:

Without operator overloading, operations would require explicit function calls (e.g., add(c1, c2) instead of c1 + c2).
Overloading allows operators to retain their intuitive, natural usage.*/
