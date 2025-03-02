#include <iostream>
#include <memory>  // For std::unique_ptr

using namespace std;

int main() {
    unique_ptr<int> p1(new int(10));  // p1 owns the memory for an integer with value 10
    
    cout << "Value: " << *p1 << endl;  // Output: 10
    
    // Move ownership to another unique_ptr
    unique_ptr<int> p2 = move(p1);  // p1 no longer owns the memory, p2 does
    
    cout << "Value: " << *p2 << endl;  // Output: 10

    // p1 is now nullptr
    if (p1 == nullptr) {
        cout << "p1 is now nullptr" << endl;
    }
 if (p2 == nullptr) {
        cout << "p2 is now nullptr" << endl;
    }
    // p2 goes out of scope here, and the memory is automatically freed

    return 0;
}
