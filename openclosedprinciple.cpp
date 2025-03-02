
#include <iostream>
using namespace std;

// Abstract base class 'shape' with a pure virtual function 'area'
// This class cannot be instantiated and is used as a base for specific shapes
class shape {
    public:
    // Pure virtual function to be overridden in derived classes
    virtual void area() = 0;
};

// 'rectangle' class inheriting from 'shape'
// Provides its own implementation of the 'area' method
class rectangle : public shape {
    public:
    int l, b;  // Length and breadth of the rectangle

    // Constructor to initialize length and breadth
    rectangle(int l, int b) {
        this->l = l;
        this->b = b;
    }

    // Overridden method to calculate and print the area of the rectangle
    void area() {
        cout << "Rectangle area = " << (l * b) << endl;
    }
};

// 'circle' class inheriting from 'shape'
// Implements the 'area' method to calculate the area of a circle
class circle : public shape {
    public:
    int r;  // Radius of the circle

    // Constructor to initialize radius
    circle(int r) {
        this->r = r;
    }

    // Overridden method to calculate and print the area of the circle
    void area() {
        float area1 = (3.14 * r * r);  // Using 3.14 as an approximation for π
        cout << "Circle area = " << area1 << endl;
    }
};

/* Following the Open/Closed Principle:
   We are adding the 'square' class for calculating area, which extends the 'shape' class
   without modifying any existing code. The 'shape' class is open for extension (by adding new shapes) 
   but closed for modification (no need to alter existing shapes).
*/

// 'square' class inheriting from 'shape'
// Implements its own 'area' method
class square : public shape {
    public:
    int l;  // Side length of the square

    // Constructor to initialize side length
    square(int l) {
        this->l = l;
    }

    // Overridden method to calculate and print the area of the square
    void area() {
        cout << "Area of square = " << (l * l) << endl;
    }
};

int main() {
    // Pointer of type 'shape' that can point to any derived class object
    shape *s;

    // Creating a 'rectangle' object and calculating its area
    rectangle r(5, 7);  // Rectangle with length 5 and breadth 7
    s = &r;  // Assigning the address of the rectangle to the shape pointer
    s->area();  // Calling the area function of rectangle

    // Creating a 'circle' object and calculating its area
    circle c(25);  // Circle with radius 25
    s = &c;  // Assigning the address of the circle to the shape pointer
    s->area();  // Calling the area function of circle

    // Creating a 'square' object and calculating its area
    square q(12);  // Square with side length 12
    s = &q;  // Assigning the address of the square to the shape pointer
    s->area();  // Calling the area function of square

    return 0;  // Exit the program
}
