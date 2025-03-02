
// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class test {
    
    private :
    int a;
    
    public:
    
    int get ()
    
    {
        return a;
    }
    
    void set(int b)
    {
        a=b;
    }
 
    
};

int main() {
    // Write C++ code here
   
   test t1 ;
   t1.set(5);
   
   cout<<t1.get();
   
    return 0;
}