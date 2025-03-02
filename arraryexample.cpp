/*Notes:
Char Array: Passed as a pointer, works well for simple strings but requires null termination.
String: Passed by reference for efficiency, safer and more modern than char arrays.
Array: Requires size information (or a template/std::vector) since it decays to a pointer.
*/
#include <iostream>
#include <string>
using namespace std;

// Function to print a char array
void printCharArray(char arr[]) {
    cout << "Char Array: " << arr << endl;
}

// Function to print a string
void printString(const string& s) {
    cout << "String: " << s << endl;
}

// Function to print an array
void printArray(int arr[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Example 1: Char Array
    char myCharArr[] = "Hello";
    printCharArray(myCharArr);

    // Example 2: String
    string myString = "World";
    printString(myString);

    // Example 3: Array
    int myArray[] = {1, 2, 3, 4};
    int size = 4;
    printArray(myArray, size);

    return 0;
}