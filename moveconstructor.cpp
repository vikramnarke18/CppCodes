/* **Move Constructor in C++**

A **move constructor** in C++ is a special constructor that moves resources from a
 temporary object (rvalue) to a new object, instead of copying them. 
 This is useful for optimizing performance, especially when working 
 with dynamically allocated memory.

### **Why Use a Move Constructor?**

- Avoids deep copies, which can be expensive.
- Transfers ownership of resources (e.g., heap memory, file handles).
- Helps optimize performance when dealing with temporary objects.

---

## **Move Constructor Syntax**

```cpp*/

#include <iostream>
using namespace std;
class MyClass {
private:
    int* data;

public:
    // Constructor
    MyClass(int value) {
        data = new int(value);
        std::cout << "Constructor called\n";
    }

    // Move Constructor
    MyClass(MyClass&& other) noexcept  {
        std::cout << "Move Constructor called\n";
        data = other.data; // Steal the pointer
        other.data = nullptr; // Nullify the source

        cout<<*data<<endl;
    }
     
     // Copy Assignment Operator
     MyClass& operator=(const MyClass& other) {
        std::cout << "Copy Assignment Operator called\n";
        if (this != &other) {  // Self-assignment check
            delete data; // Free existing resource
            data = new int(*other.data); // Deep copy
        }
        return *this;
    }

    // Destructor
    ~MyClass() {

        cout << "Destructor called\n";
        delete data;
    }
};





int main() {
    MyClass obj1(10);        // Normal constructor
    MyClass obj2 = move(obj1); // Move constructor
    MyClass obj3(20);
    obj3=obj2;

    return 0;
}

/*

### **Key Points**

1. `std::move(obj1)` converts `obj1` into an rvalue.
2. The move constructor transfers ownership of `data` from `obj1` to `obj2`.
3. `obj1.data` is set to `nullptr` to prevent double deletion.
4. No deep copy occurs, making it efficient.

---

### **When is the Move Constructor Called?**

- When returning a temporary object from a function.
- When passing a temporary object to a function by value.
- When using `std::move()` on an object.
*/
