#include "builder.h"

class Package2 : public Vacation {
public:
    void bookHotels() override;
    void bookFlights() override;
    void bookTours() override;
};
