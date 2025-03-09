#include <iostream>
using namespace std;

template <typename T>
class unique {
private:
    T* ptr;

public:
    // Constructor
    unique(T* p) : ptr(p) {
        cout << "Resource Acquired" << endl;
    }

    // Destructor
    ~unique() {
        delete ptr;
        cout << "Resource Freed" << endl;
    }

    // Move Constructor
    unique(unique&& obj) noexcept {
        ptr = obj.ptr;
        obj.ptr = nullptr;
        cout << "Move Constructor" << endl;
    }

    // Move Assignment Operator
    unique& operator=(unique&& obj) noexcept {
        if (this != &obj) {  // Prevent self-assignment
            delete ptr;  // Free existing resource
            ptr = obj.ptr;  // Transfer ownership
            obj.ptr = nullptr;  // Nullify source
            cout << "Move Assignment" << endl;
        }
        return *this;
    }

    // Deleted Copy Constructor & Copy Assignment
    unique(const unique&) = delete;
    unique& operator=(const unique&) = delete;
};

class test {
public:
    test() {
        cout << "Constructor" << endl;
    }
    ~test() {
        cout << "Destructor" << endl;
    }
};

int main() {
    unique<test> p1(new test());  // Creates object
    unique<test> p2(new test());  // Creates another object
    p2 = move(p1);  // Move Assignment (p2 takes ownership of p1's resource)

    return 0;  // p2 is destroyed and frees the resource
}
