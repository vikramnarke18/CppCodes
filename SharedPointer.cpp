#include <iostream>
#include <memory>
using namespace std;

void func()
{
    shared_ptr<int> p1(new int(100));  // p1 owns an int with value 100


    shared_ptr<int>p4=make_shared<int>(300) ;

    cout<<*p4<<endl;    
    shared_ptr<int> p2;  // p2 is an empty shared_ptr
    
    p2 = p1;  // Now p1 and p2 both share ownership of the integer 100
    
    cout << *p2 << endl;  // Output the value: 100
    
    // Output the reference count (how many shared_ptrs own the object)
    cout << p1.use_count() << endl;  // Output: 2 (p1 and p2 both point to the object)
    cout << p2.use_count() << endl;  // Output: 2 (p1 and p2 both point to the object)
    
    p1.reset();  // p1 is reset, so it no longer points to the object. p2 still owns the object.
    
    cout << p1.use_count() << endl;  // Output: 0 (p1 is reset, so no longer owns the object)
    cout << p2.use_count() << endl;  // Output: 1 (p2 is the only one pointing to the object now)
    
    // Output the raw pointers held by p1 and p2
    cout << p1.get() << endl;  // Output: 0 (p1 no longer holds a valid pointer)
    cout << p2.get() << endl;  // Output: address of the int (p2 still owns the object)
}

int main()
{
    func();  // Call the func() function
    
    return 0;
}
