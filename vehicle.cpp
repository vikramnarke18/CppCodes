#ifndef VEHICLE_HPP
#define VEHICLE_HPP

class Vehicle {
public:
    virtual void createVehicle() = 0; // Pure virtual function
    virtual ~Vehicle() {} // Virtual destructor (optional, but good practice)
};

#endif // VEHICLE_HPP
