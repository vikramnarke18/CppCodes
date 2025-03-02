// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Base {
private:
 void show1() {  // Private virtual function
        cout << "Base class show()" << endl;
    }

public:
    void display() {
        show1();  // Indirect access via public method
    }
};

class Derived : public Base {
public:
    void show()  {  // Overriding private virtual function
        cout << "Derived class show()" << endl;
    }
};

int main() {
    
    Base b;
    //b.show1();
    b.display();
    
    Derived d;
    d.show();
  //  d.show1();
    d.display();
 
    return 0;
}

/*Object slicing in C++ occurs when an object of a derived class is assigned to an object of a base class by value, resulting in the loss of derived class-specific attributes and behaviors.
 Only the base class part is retained, while the derived class-specific members are "sliced off."*/
