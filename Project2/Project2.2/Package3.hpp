#include "builder.h"

class Package3 : public Vacation {
public:
    void bookHotels() override;
    void bookFlights() override;
    void bookTours() override;
};
