#include <iostream>
#include<cstring>
using namespace std;

void reverse(char str[] )
{
    int start=0;
    int end=strlen(str)-1 ;
    
    while (start<end)
    {
        swap(str[start], str[end]);
        start++;
        end--;
    }
}
int main() {
    
    char str[100];
    
    cout<<"Enter a string=";
    cin.getline(str,100);

    reverse(str);
    cout<<"String="<<str;
    

    return 0;
}