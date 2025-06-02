#ifndef pickup_order_H
#define pickup_order_H
#include "Order.h"
using namespace std;

class PickupOrder : public Order {
private:
    string restaurantAddress;
public:
    PickupOrder() {
        restaurantAddress = "";
    }

    string getType() const override {
        return "Pickup";
    }

    string getRestaurantAddress() const {
        return restaurantAddress;
    }
    void setRestaurantAddress(const string& addr) {
        restaurantAddress = addr;
    }
};

#endif // pickup_order_H