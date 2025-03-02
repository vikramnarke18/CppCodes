#include <iostream>  // Include the iostream library for input-output operations
#include <cstring>   // Include cstring for strcpy() and strlen()
using namespace std;

// Define a class named 'movie'
class movie {
public:
    char* Name;  // Pointer to store the movie name
    int Rating;  // Public member variable to store the rating of the movie

    // Parameterized constructor
    movie(const char* name, int rating) {
        // Allocate memory for Name and copy the string
        Name = new char[strlen(name) + 1];  // +1 for null terminator
        strcpy(Name, name);
        Rating = rating;

        // Print constructor message
        cout << "Parameterized constructor" << endl;
        cout << Name << " = " << Rating << endl;
    }

    // Copy constructor (deep copy)
    movie(const movie& obj) {
        // Allocate new memory and copy the contents
        Name = new char[strlen(obj.Name) + 1];
        strcpy(Name, obj.Name);
        Rating = obj.Rating;

        // Print copy constructor message
        cout << "Copy constructor" << endl;
        cout << Name << " == " << Rating << endl;
    }

    // Copy assignment operator (deep copy)
    movie& operator=(const movie& obj) {
        if (this == &obj)  // Self-assignment check
            return *this;

        // Free the existing memory
        delete[] Name;

        // Allocate new memory and copy contents
        Name = new char[strlen(obj.Name) + 1];
        strcpy(Name, obj.Name);
        Rating = obj.Rating;

        // Print copy assignment message
        cout << "Copy assignment operator" << endl;
        cout << Name << " === " << Rating << endl;

        return *this;  // Return reference to the current object
    }

    // Destructor to free allocated memory
    ~movie() {
        delete[] Name;  // Free dynamically allocated memory
        cout << "Destructor called for " << Name << endl;
    }
};

// Main function
int main() {
    // Creating an object 'm1' using the parameterized constructor
    movie m1("Vikram", 8);

    // Creating an object 'm2' as a copy of 'm1' using the copy constructor
    movie m2 = m1;

    // Creating an object 'm3' using the parameterized constructor
    movie m3("Narke", 9);

    // Assigning 'm1' to 'm3' using the copy assignment operator
    m3 = m1;

    return 0;  // Indicate successful program execution
}
