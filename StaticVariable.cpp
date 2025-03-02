#include <iostream>  
using namespace std;

class test {
    public:
    int a, b;
    static int count;  // Declaration of static variable

    test(int a, int b) {
        this->a = a;
        this->b = b;
        count++;  // Increment count when an object is created
    }

    void display() {
        cout << "Values=" << a << " " << b << endl;
    }
};

// Definition of static member variable outside the class
int test::count = 0;  

int main() {
    test c1(20, 30);
    test c2(60, 70);
    c1.display();
    c2.display();
    cout << "Number of objects created = " << test::count << endl;  // Access static variable with class name

    return 0;
}
