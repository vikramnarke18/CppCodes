
#include <iostream>  // Include the input-output stream library

using namespace std;  // Use the standard namespace

 int search(int a[], int m )
 {
     for (int i=0;i<5;i++)
     {
         if (a[i]==m)
         {
             return i;
         }
     }
     return -1;
 }


int main() {
    
    int a[10]={5,6,10,1};
    
    int n=10;
    
    //search(a, n);
    
    int result = search(a, n);

    if (result != -1) {
        std::cout << "Element found at index " << result << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }
    
   
   
   
   
    return 0;
}

