#include <iostream>
using namespace std;

class Test {
public:
    int a, b;
    int* p ;
   

    // Constructor
    Test(int x, int y, int z) {
         p= new int;
        a = x;
        b = y;
        *p = z;
    }

    // Show function to display values
    void show() {
        cout << "Values are: a = " << a << ", b = " << b << ", p = " << *p << endl;
    }

    // Copy constructor
    Test( const Test &obj) {
        a = obj.a;
        b = obj.b;
        p = new int;
        *p = *(obj.p);
    }

    // Destructor to free memory
    ~Test() {
        delete p;
    }
};

int main() {
    // Creating object t1 and displaying its values
    Test t1(5, 10, 15);
    t1.show();

    // Creating object t2 as a copy of t1 and displaying its values
    Test t2 (t1);
    t2.show();

    return 0;
    

}


/*If we don’t define our own copy constructor, the C++ compiler
 creates a default copy constructor for each class which works fine in general. 
 However, we need to define our own copy constructor only if an object has pointers or
  any runtime allocation of the resource like a file handle, a network connection, 
  etc because the default constructor does only shallow copy.*/



  /*Shallow Copy means that only the pointers will be copied not the actual
   resources that the pointers are pointing to. This can lead 
   to dangling pointers if the original object is deleted.*/


   /*Deep copy is possible only with a user-defined copy constructor. 
   In a user-defined copy constructor, we make sure that pointers (or references) 
   of copied objects point to new copy of the dynamic resource allocated manually\
    in the copy constructor using new operators.  */


   /*Object	Member Variables (Stack)	Dynamic Memory (Heap)
t1	a=2, b=3, p → (points to heap)	*t1.p = 4
t2	a=2, b=3, p → (points to heap)	*t2.p = 4*/


