//Counting Semaphore – Allows multiple threads to access a
//  resource up to a specified limit.

//A semaphore is a synchronization mechanism used in concurrent programming to control 
// access to shared resources. 
//It prevents race conditions and ensures proper resource management among multiple threads.


#include <iostream>
#include <thread>
#include <semaphore>

std::counting_semaphore<2> sem(2); // Allows 2 concurrent accesses

void task(int id) {
    sem.acquire(); // Decrement semaphore count
    std::cout << "Thread " << id << " is executing\n";
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate work
    std::cout << "Thread " << id << " finished\n";
    sem.release(); // Increment semaphore count
}

int main() {
    std::thread t1(task, 1);
    std::thread t2(task, 2);
    std::thread t3(task, 3);
    
    t1.join();
    t2.join();
    t3.join();
    
    return 0;
}

/*Thread 1 is executing
Thread 2 is executing
Thread 1 finished
Thread 3 is executing
Thread 2 finished
Thread 3 finished  */