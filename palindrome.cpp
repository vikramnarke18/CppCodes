#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[] = "ABBA"; // Example palindrome string

    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            cout << "String is NOT a palindrome" << endl;
            return 0; // Exit immediately
        }
        start++;
        end--;
    }

    cout << "String is a palindrome" << endl;
    return 0;
}
