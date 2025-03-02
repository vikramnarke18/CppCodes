#include <iostream>
#include <memory>
using namespace std;

class MyClass {
public:
    MyClass() { std::cout << "MyClass Constructor\n"; }
    ~MyClass() { std::cout << "MyClass Destructor\n"; }
    void display() const { std::cout << "Hello from MyClass\n"; }
};

int main() {
    // Create a shared_ptr managing a new MyClass object
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();

    {
        // Create another shared_ptr sharing ownership of the same object
        std::shared_ptr<MyClass> ptr2 = ptr1;

        // Use the shared_ptr to access MyClass methods
        ptr2->display();

        // Reference count is now 2
        std::cout << "Reference Count: " << ptr1.use_count() << '\n';
    } // ptr2 goes out of scope, reference count decreases to 1

    // Reference count is now 1
    std::cout << "Reference Count: " << ptr1.use_count() << '\n';

    // Reset ptr1, reference count becomes 0, MyClass object is destroyed
    ptr1.reset();

    // Reference count is now 0
    std::cout << "Reference Count: " << ptr1.use_count() << '\n';

    return 0;
}


/*In C++, a std::shared_ptr is a smart pointer that manages the lifetime of a dynamically 
allocated object through reference counting. Multiple shared_ptr instances can own the same object, 
and the resource is automatically deallocated when the last shared_ptr owning it is destroyed or reset. 
CPPREFERENCE

Key Characteristics:

Reference Counting: Each shared_ptr maintains a reference count indicating 
how many shared_ptr instances share ownership of the same object. 
This count is incremented when a new shared_ptr is created from an existing one and
 decremented when a shared_ptr is destroyed or reset. 
STACK OVERFLOW

Automatic Deallocation: When the reference count drops to zero, meaning 
no shared_ptr instances own the object, the managed resource is automatically deleted, ensuring proper memory management. 
CPPREFERENCE

Shared Ownership: Multiple shared_ptr instances can own the same resource,
 making it suitable for scenarios where shared access to a resource is needed.*/