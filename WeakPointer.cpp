#include <iostream>
#include <memory>
using namespace std;

void func()
{
    // Create a shared_ptr named p1 that points to a dynamically allocated integer with the value 100
    shared_ptr<int> p1(new int(100));
    
    // Create a weak_ptr named p2 that references the same object as p1, but without owning it
    weak_ptr<int> p2 = p1;
    
    // Display the use count (how many shared_ptrs own the object)
    cout << p1.use_count() << endl;  // Output: 1 (p1 is the only owner)
    cout << p2.use_count() << endl;  // Output: 1 (weak_ptr doesn't affect the use count)
    
    // Display the value of the object through p1 (shared_ptr)
    cout << "Value of p1 = " << *p1 << endl;  // Output: 100
    
    // Lock p2 (weak_ptr) to get a shared_ptr and then access the value
    cout << "Value of p2 = " << *(p2.lock()) << endl;  // Output: 100
    
    // Reset p1, meaning it releases ownership of the object, which should deallocate the memory
    p1.reset();
    
    // Display the use count again
    cout << p1.use_count() << endl;  // Output: 0 (p1 no longer owns the object)
    cout << p2.use_count() << endl;  // Output: 0 (the object has been deallocated)
}

int main()
{
    func();  // Call the function

    return 0;
}
