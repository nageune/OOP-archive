#include "builder.h"

class Package1 : public Vacation {
public:
    void bookHotels() override;
    void bookFlights() override;
    void bookTours() override;
};
