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
    // Create a unique_ptr managing a new MyClass object
    unique_ptr<MyClass> ptr1 = make_unique<MyClass>();

    // Use the unique_ptr to access MyClass methods
    ptr1->display();

    // Transfer ownership to another unique_ptr using std::move
    std::unique_ptr<MyClass> ptr2 = std::move(ptr1);

    // ptr1 is now empty; ptr2 owns the MyClass object
    if (!ptr1) {
        std::cout << "ptr1 is empty\n";
    }

    // ptr2 can still access MyClass methods
    ptr2->display();

    // When ptr2 goes out of scope, MyClass is automatically destroyed
    return 0;
}

/*In C++, a std::unique_ptr is a smart pointer that exclusively owns and manages a
 dynamically allocated object. It ensures that the object's lifetime is controlled, 
 automatically deallocating the memory when the unique_ptr goes out of scope.
  This exclusive ownership prevents multiple pointers from managing the same resource, 
  thereby reducing the risk of memory leaks and dangling pointers.*/