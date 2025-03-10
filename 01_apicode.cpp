#include <iostream>
using namespace std;

// Function to count trailing 9's in a number
int countTrailingNines(long long num) {
    int count = 0;
    while (num % 10 == 9) {
        count++;
        num /= 10;
    }
    return count;
}

// Optimized function to find the best price
long long findBestPrice(long long minPrice, long long maxPrice) {
    long long bestPrice = minPrice;
    int maxNines = countTrailingNines(minPrice);

    for (long long i = maxPrice; i >= minPrice; ) {
        int trailingNines = countTrailingNines(i);

        // Update bestPrice if the current number has more trailing 9s
        if (trailingNines > maxNines || (trailingNines == maxNines && i > bestPrice)) {
            maxNines = trailingNines;
            bestPrice = i;
        }

        // Move efficiently to the next largest number ending in 9
        if (i % 10 == 9) {
            i--;  // If i already ends in 9, decrement normally
        } else {
            i -= (i % 10 + 1);  // Move directly to the next closest number ending in 9
            while (i % 10 != 9 && i >= minPrice) { 
                i--; // Ensure we land on a number ending in 9
            }
        }
    }

    return bestPrice;
}

int main() {
    // Example test cases
    long long a, b;
    cout << "Enter the minimum price: ";   
    cin >> a;   
    cout << "Enter the maximum price: ";
    cin >> b;   
    cout << "Best price: " << findBestPrice(a, b) << endl;

    return 0;
}
