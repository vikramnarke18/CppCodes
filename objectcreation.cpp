
#include <iostream>
using namespace std;

class test {
public:
    int a;
    int b;

    int area() {
        return a * b;
    }
};

int main() {
    test t1;   // Stack allocation
    t1.a = 15;
    t1.b = 10;
    cout << "stack="<<t1.area() << endl;  // Output: 150

    test *t2 = new test();  // Heap allocation
    t2->a = 4;
    t2->b = 10;
    cout << "Heap=" << t2->area() << endl;  // Output: 40

    delete t2;  // Deallocate heap memory

    return 0;
}
