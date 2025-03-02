// Online C++ compiler to run C++ program online 
//Templates in C++ allow writing generic and reusable code. 
// Instead of writing functions or classes that work with specific data types,
//  templates enable defining a single piece of code that can work with any data type.
#include <iostream>
using namespace std;

template <typename T>
T print(T x)
{
    cout<<"Value="<<x<<endl;
    return x;
}

int main() {
    // Write C++ code here
   print(2);
   print(2.5);
   print("Vikram");

    return 0;
}