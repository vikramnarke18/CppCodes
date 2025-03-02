#include <iostream>
using namespace std;

class A {
public:
    void funA() {
        cout << "I am class A\n";
    }
};

class B : virtual public A {
public:
    void funB() {
        cout << "I am class B\n";
    }
};

class C : virtual public A {
public:
    void funC() {
        cout << "I am class C\n";
    }
};

class D : public B, public C {
public:
    void funD() {
        cout << "I am class D\n";
    }
};

int main() {
    D d; // Proper instantiation of class D
    d.funA(); // Calling funA() from class A
    d.funB(); // Calling funB() from class B
    d.funC(); // Calling funC() from class C
    d.funD(); // Calling funD() from class D


        
    // To avoid ambiguity, explicitly call Base class methods
    //If virtual inheritance is not used, specify explicitly which parent’s function to call.
    d.B::funA();
    d.C::funA();
    d.D::funA();
    
    return 0;
}

/*✔ Combines different inheritance types for flexibility.
✔ Ambiguity issue (due to multiple inheritance) is resolved using scope resolution (::).
✔ Useful in complex class hierarchies, such as GUI frameworks and device drivers.*/
