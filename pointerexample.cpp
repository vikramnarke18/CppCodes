// Online C++ compiler to run C++ program online
#include <iostream>
#include <memory>
using namespace std;

class test{
    public:
    test(){  //default constructor
        cout<<"Test"<<endl;
    }
    test(int a){                            //parameterized constructor
        cout<<"Test"<<endl;
    }
};


int main() {
   test *ptr=new test();//if we creating pointer of class then object is created using new keyword
   unique_ptr<test>p1=make_unique<test>();
   delete ptr;

test *ptr2=new int(100);
unique_ptr<test>p2=make_unique<test>(100);
delete ptr2;

    cout<<"Vikram"<<endl;

    // Over time, the unreleased memory accumulates
    return 0;
}
   