#include <iostream>
using namespace std;

class base {
public:
    virtual void print() { cout << "print base class\n"; }
    void show() { cout << "show base class\n"; }
};

class derived : public base {
public:
    void print() { cout << "print derived class\n"; }
    void show() { cout << "show derived class\n"; }
};

int main() {
    base *bptr=new derived() ; // Upcasting
    bptr->print();
    bptr->show();

    derived *d1 = dynamic_cast<derived *>(bptr);  // Downcasting
    if (d1) { // Always check if the dynamic_cast succeeded
        d1->show();
        d1->print();
    } else {
        cout << "dynamic_cast failed\n";
    }

    return 0;
}
