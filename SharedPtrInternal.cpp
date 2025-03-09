#include <iostream>
using namespace std;

template <typename T>
class shared_ptr {
private:
    T* ptr;  // Pointer to managed object
    int* ref_count;  // Reference count

public:
    // Constructor
    shared_ptr(T* p = nullptr) : ptr(p) {
        if (p) {
            ref_count = new int(1);  // Initialize ref count to 1
        } else {
            ref_count = nullptr;
        }
    }

    // Copy Constructor (Increments ref_count)
    shared_ptr(const shared_ptr& other) {
        ptr = other.ptr;
        ref_count = other.ref_count;
        if (ref_count) (*ref_count)++;
    }

    // Destructor (Decreases ref_count, deletes resource if needed)
    ~shared_ptr() {
        if (ref_count) {
            (*ref_count)--;
            if (*ref_count == 0) {  // Last owner
                delete ptr;
                delete ref_count;
                cout << "Resource Freed" << endl;
            }
        }
    }

    // Get reference count
    int use_count() const {
        return ref_count ? *ref_count : 0;
    }

    // Get raw pointer
    T* get() const { return ptr; }
};

class Test {
public:
    Test() { cout << "Constructor\n"; }
    ~Test() { cout << "Destructor\n"; }
};

int main() {
    shared_ptr<Test> p1(new Test()); // Reference count = 1
    cout << "Use count: " << p1.use_count() << endl;

    {
        shared_ptr<Test> p2 = p1; // Reference count = 2
        cout << "Use count: " << p1.use_count() << endl;
    } // p2 goes out of scope, Reference count = 1

    cout << "Use count after p2 destroyed: " << p1.use_count() << endl;
    return 0;
} // p1 destroyed, Reference count = 0, Object deleted
