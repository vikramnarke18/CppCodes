
//https://onecompiler.com/cpp/43683mku2
#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include <condition_variable>
using namespace std;
mutex mu;
condition_variable cond;
deque<int> buffer;
const int maxBufferSize=10;

void producer(int val)
{
   
    while(val)
    {
        unique_lock<mutex> locker(mu);
        cond.wait(locker,[]{return buffer.size()<maxBufferSize;});
        buffer.push_back(val);
        cout<<"Produced="<<val<<endl;
        val--;
        locker.unlock();
        cond.notify_one();
        
        
    }
}
void consumer()
{
    
    while(true)
    {
        unique_lock<mutex> locker(mu);
        cond.wait(locker,[]{return buffer.size()>0;});
        int val=buffer.back();
        buffer.pop_back();
        cout<<"Consumed="<<val<<endl;
        locker.unlock();
        cond.notify_one();
    }
}

int main() {
    thread t1(producer ,10);
    thread t2(consumer);
    
    t1.join();
    t2.join();

return 0;
}

