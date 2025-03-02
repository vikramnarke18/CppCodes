#include <iostream>
using namespace std;

int main() {
    // Char Array and Pointer
    char str[] = "Hello";  // Char array
    char* charPtr = str;   // Pointer to char array

    cout << "Char Array: " << charPtr << endl;  // Prints "Hello"
    cout << "First character: " << *charPtr << endl;  // Prints 'H'
    cout << "Second character: " << *(charPtr + 1) << endl;  // Prints 'e'

    cout << "\n";

    // Integer Array and Pointer
    int arr[] = {10, 20, 30, 40};  // Integer array
    int* intPtr = arr;  // Pointer to first element

    cout << "Integer Array Elements using Pointer: " << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Element " << i << ": " << *(intPtr + i) << endl;
    }

    return 0;
}
