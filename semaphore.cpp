#include <iostream>
#include <thread>
#include <semaphore> // C++20 feature

using namespace std;

counting_semaphore<2> sem(2); // Semaphore allowing 2 threads at a time

void task(int id) {
    sem.acquire(); // Wait (decrement semaphore)
    cout << "Thread " << id << " is accessing the resource." << endl;
    this_thread::sleep_for(chrono::seconds(1)); // Simulate work
    cout << "Thread " << id << " is releasing the resource." << endl;
    sem.release(); // Signal (increment semaphore)
}

int main() {
    thread t1(task, 1);
    thread t2(task, 2);
    thread t3(task, 3);
    thread t4(task, 4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}
