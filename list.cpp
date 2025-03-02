#include <iostream>
#include <list>
#include <iterator>
using namespace std;

int main()
{
    list<int> l;
    l.push_front(52);
    l.push_front(14);
    l.push_back(222);

    // Advance the iterator to the second position
    auto it = l.begin();
    advance(it, 2); // Move iterator to the second position  //std::advance adjusts the position of a bidirectional iterator by the given number of steps.
    l.insert(it, 20); // Insert 20 at the second position

    // Print the list
    for (auto i : l)
    {
        cout << i << endl;
    }

    return 0;
}
