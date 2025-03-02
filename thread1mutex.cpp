#include <iostream>
#include <thread>
#include <mutex>
#include <chrono> // Include for chrono::seconds

using namespace std;

mutex carMutex;

void driveCar(string name) {
    unique_lock<mutex> Lock(carMutex); // Acquire lock immediately

    cout << name << " is driving" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << name << " is done driving" << endl;
    Lock.unlock();

    // Implicit unlock when carLock goes out of scope
}

int main() {
    thread t1(driveCar, "Vikram");
    thread t2(driveCar, "Ram");

    t1.join();
    t2.join();

    return 0; // Good practice to return 0 from main
}