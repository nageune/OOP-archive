#pragma once
#include <iostream>
#include <string>
using namespace std;

class Vacation {
public:
    virtual void bookHotels() = 0;
    virtual void bookFlights() = 0;
    virtual void bookTours() = 0;
};
