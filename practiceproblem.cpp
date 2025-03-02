// A program with virtual destructor
#include <iostream>
#include <vector>
using namespace std;



int main()
{
vector<int>v={5,9,10};
v.push_back(1004);
v.push_back(15);
v.push_back(15);
//v.pop_back();
cout<<v.size()<<endl;
cout<<v.capacity();

return 0;
}




