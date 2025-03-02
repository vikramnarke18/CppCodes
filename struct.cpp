/*notes  https://www.javatpoint.com/cpp-structs  */
//only difference between struct and class is that struct members are public by default and class members are private by default.


#include <iostream>    
using namespace std;    
 struct Rectangle      
{      
   int width, height;      
      
 };      
int main(void) {    
   Rectangle rec;    
    rec.width=8;    
    rec.height=5;    
   cout<<"Area of Rectangle is: "<<(rec.width * rec.height)<<endl;    
 return 0;    
}    