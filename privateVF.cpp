#include <iostream>
using namespace std;

class Base {
private:
    virtual void show() {  // Private virtual function
        cout << "Base class show()" << endl;
    }

public:
    void display() {
        show();  // Indirect access via public method
    }
};

class Derived : public Base {
private:
    void show() override {  // Overriding private virtual function
        cout << "Derived class show()" << endl;
    }
};

int main() {
    Derived d;
    d.display();  // Calls Derived's show() via Base's display()

    // d.show();  // Error: 'show' is private within this context

    return 0;
}
