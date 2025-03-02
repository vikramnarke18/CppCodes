#include <iostream>
using namespace std;

// 1. Product: Abstract base class
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
    virtual ~Shape() {}
};

// 2. ConcreteProduct: Derived classes
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Circle." << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Rectangle." << endl;
    }
};

class Triangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Triangle." << endl;
    }
};

// 3. Factory: A class to create objects
class ShapeFactory {
public:
    static Shape* createShape(const string& shapeType) {
        if (shapeType == "Circle")
            return new Circle();
        else if (shapeType == "Rectangle")
            return new Rectangle();
        else if (shapeType == "Triangle")
            return new Triangle();
        else
            return nullptr; // Invalid shape type
    }
};

// 4. Client Code
int main() {
    // Create shapes using the factory
    Shape* shape1 = ShapeFactory::createShape("Circle");
    Shape* shape2 = ShapeFactory::createShape("Rectangle");
    Shape* shape3 = ShapeFactory::createShape("Triangle");

    // Use the shapes
    if (shape1) {
        shape1->draw();
        delete shape1; // Manually delete to avoid memory leak
    }

    if (shape2) {
        shape2->draw();
        delete shape2; // Manually delete to avoid memory leak
    }

    if (shape3) {
        shape3->draw();
        delete shape3; // Manually delete to avoid memory leak
    }

    return 0;
}

/*Advantages Demonstrated in This Example
Encapsulation of Object Creation: The logic for creating shapes is encapsulated in the factory, so 
the client doesn't need to know how objects are created.
Abstraction and Polymorphism: The client interacts with Shape objects and uses the common interface draw(). 
The actual implementation of draw() is determined by the concrete shape class (circle, triangle, or square), 
enabling polymorphism.
Flexible and Extendable: You can easily add more shapes (e.g., Rectangle, Hexagon) by creating a new class 
derived from Shape and modifying the ShapeFactory to return that shape. The client code does not need to be changed.
Centralized Creation Logic: The factory centralizes the object creation logic, making it easier 
to manage and modify. If, for example, creating a Circle involved complex setup, that logic 
could be placed in the Circle class, and the factory would handle it internally.*/