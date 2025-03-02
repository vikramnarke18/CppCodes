// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class singleton {
    
    private :
    
    singleton()
    {
        cout<<"I am private constructor"<<endl ;
    }
    
    public :
    static int count;
    
    static singleton *getinstance ()
    {
        if (count==0)
        {   
            count++ ;
            return new singleton();
            
        
        }
        else{
            return nullptr;
        }
        
    }


    
};

int singleton::count =0;

int main() {
    // Write C++ code here
  singleton ::getinstance ();

    return 0;
}