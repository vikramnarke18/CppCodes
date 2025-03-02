// A program with virtual destructor
#include <iostream>

using namespace std;

class base {
public:
	base()	 
	{ cout << "Constructing base\n"; }
	virtual ~base()
	{ cout << "Destructing base\n"; }	 
};

class derived : public base {
public:
	derived()	 
	{ cout << "Constructing derived\n"; }
	~derived()
	{ cout << "Destructing derived\n"; }
};

int main()
{

base *b = new derived();
delete b;

return 0;
}





/*When you allocate an object dynamically using new, it is created on the heap,
 and you must manually manage its lifetime. This includes explicitly deallocating the memory using delete.
If you don’t call delete, the object stays on the heap, and its destructor is not called. 
This leads to a memory leak because the dynamically allocated memory is not released. */

/*A virtual destructor is essential when you intend to delete a derived 
object using a base class pointer. Without a virtual destructor, only the base class
 destructor will be invoked, leading to potential resource leaks or undefined behavior 
 if the derived class allocates dynamic memory.
 
 
derived *d = new derived(); 
base *b = d;
delete b;

*/


/*It is correct that a virtual destructor is not required in this specific case
 because the delete operator is called on a pointer to the derived class (derived *d).

When the destructor is called directly on an object of the derived class 
(not through a base class pointer), the destructor sequence executes properly
 for both the derived and base class destructors, as demonstrated in your program's output: 
 derived *d = new derived(); 
 delete d;*/