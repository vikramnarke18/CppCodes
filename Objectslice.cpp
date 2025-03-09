#include <iostream>
using namespace std;

class Base {
public:
    int baseValue = 10;

    void show() {
        cout << "Base value4: " << baseValue << endl;
    }
};

class Derived : public Base {
public:
    int derivedValue = 20;

    void show() {
        cout << "Base value1: " << baseValue << ", Derived value: " << derivedValue << endl;
    }
};

int main() {
    Derived d;
    Base b = d;  // Object slicing occurs here

    b.show();  // Calls Base class's show()

    return 0;
}
