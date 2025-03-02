//https://www.youtube.com/watch?v=pKKXGxEapaU
#include <iostream>  // Include the iostream library for input-output operations
using namespace std;

// Define a class named 'movie'
class movie {  
public:
    string Name;  // Public member variable to store the name of the movie
    int Rating;   // Public member variable to store the rating of the movie

    // Parameterized constructor
    movie(string name, int rating) {
        Name = name;  // Assign parameter 'name' to class member 'Name'
        Rating = rating;  // Assign parameter 'rating' to class member 'Rating'
        
        // Print constructor message
        cout << "Parameterized constructor" << endl;
        cout << Name << " = " << Rating << endl;
    }

    // Copy constructor (creates a new object from an existing object)
    movie(const movie &obj) {
        Name = obj.Name;  // Copy the movie name
        Rating = obj.Rating;  // Copy the movie rating
        
        // Print copy constructor message
        cout << "Copy constructor" << endl;
        cout << Name << " == " << Rating << endl;
    }

    // Copy assignment operator (assigns values from one object to another)
    movie& operator=(const movie &obj) {     
        Name = obj.Name;  // Copy the movie name
        Rating = obj.Rating;  // Copy the movie rating
        
        // Print copy assignment message
        cout << "Copy assignment constructor" << endl;
        cout << Name << " === " << Rating << endl;
        
        return *this;  // Return reference to the current object
    }
    movie (const movie&& obj)
    {
        Name = obj.Name;  // Copy the movie name
        Rating = obj.Rating;  // Copy the movie rating
        cout<<"Move constructor"<<endl;
        cout<<Name<<" = "<<Rating<<endl;
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
    
    movie m4 = move(m1);
    return 0;  // Indicate successful program execution
}
