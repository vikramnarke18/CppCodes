#include <iostream>
#include <string>
using namespace std;

// Function to find the missing number in a numeric string
int findMissingNumber(string s) {
    int n = s.size();

    // Try different possible lengths for the first number
    for (int length = 1; length <= n / 2; ++length) {
        int prev = stoi(s.substr(0, length)); // Extract the first number
        int missing = -1;
        bool found = false;
        size_t i = length;

        while (i < n) {
            int nextExpected = prev + 1;
            int nextLen = to_string(nextExpected).size();

            if (i + nextLen > n) break; // Prevent out-of-bounds access

            int current = stoi(s.substr(i, nextLen));

            if (current == nextExpected) {
                prev = current; // Continue sequence
            } else if (current == nextExpected + 1 && missing == -1) {
                missing = nextExpected; // Found missing number
                prev = current; // Move to the next expected number
            } else {
                break; // Sequence is broken
            }

            i += to_string(prev).size(); // Move to the next number
        }

        if (i == n && missing != -1) {
            return missing; // If we reached the end and found a missing number
        }
    }
    return -1; // No missing number found
}

// Driver Code
int main() {
    string input;
    cout<<"Input a string = ";
    cin>>input;
    
    cout << "Missing Number: " << findMissingNumber(input) << endl;
    return 0;
}
