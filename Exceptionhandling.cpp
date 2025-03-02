#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
  
  try{
    int a,b;
    cout<<"Enter two numbers"<<endl;
    cin>>a>>b;
    if (b==0)
    {
        throw invalid_argument("Number cannot be 0");
        
    }
    
    double result;
    result=a/b;
    cout<<result;
    
  }
  catch(exception &e)
  {
      cout<<e.what();
      
  }
  
  return 0;
}