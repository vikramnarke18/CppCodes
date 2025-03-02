#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class
class Vehicle {
public:
    virtual void createVehicle() = 0; // Pure virtual function
    virtual ~Vehicle() {}             // Virtual destructor
};

// Concrete Class: Car
class Car : public Vehicle {
public:
    void createVehicle() override {
        cout << "Car created!" << endl;
    }
};

// Concrete Class: Bike
class Bike : public Vehicle {
public:
    void createVehicle() override {
        cout << "Bike created!" << endl;
    }
};

// Factory Class
class VehicleFactory {
public:
    static Vehicle* createVehicle(const string& type) {
        if (type == "Car") {
            return new Car();
        } else if (type == "Bike") {
            return new Bike();
        } else {
            return nullptr;
        }
    }
};

// Main Function
int main() {
    string vehicleType;
    cout << "Enter vehicle type (Car/Bike): ";
    cin >> vehicleType;

    Vehicle* vehicle = VehicleFactory::createVehicle(vehicleType);

    if (vehicle) {
        vehicle->createVehicle(); // Call the appropriate method
        delete vehicle;           // Clean up dynamically allocated memory
    } else {
        cout << "Invalid vehicle type!" << endl;
    }

    return 0;
}
