#include<iostream>
using namespace std;
class base{
    public:
    void f1()
     {
        cout<<"Base f1"<<endl;
    }
    virtual void f2()
     {
        cout<<"Base f2"<<endl;
    }
    virtual void f3()
     {
        cout<<"Base f3"<<endl;
    }
    virtual void f4()
     {
        cout<<"Base f4"<<endl;
    }
};
class derived :public base 
{
    public:
    void f1()
     {
        cout<<"Derived f1"<<endl;
    }
    void f2()
    {
    cout<<"Derived f2"<<endl;
    }
    void f4(int x)
    {
        cout<<"Derived f4"<<endl;
    }
    };
int main (){
    derived d;
    base *bptr;
    bptr=&d;
    bptr->f1();
    bptr->f2();
    bptr->f3();
    bptr->f4();
    
}

