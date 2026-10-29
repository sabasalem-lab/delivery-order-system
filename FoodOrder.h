//Saba Salem

#ifndef FOODORDER_H
#define FOODORDER_H

#include "DeliveryOrder.h"
#include "InvalidInput.h"
#include <string>
#include <iostream>
using namespace std;

class FoodOrder : public DeliveryOrder {
private:
    string restaurantName;
    int foodCount;

public:
    FoodOrder(const string &name,
              const string &date,
              const string &phone,
              float miles,
              const string &restaurantName);

    ~FoodOrder();

    void receipt() const override;

    float VIPdiscount() const override;

    // addFood: main course name, sides default to 0, soup default to false
    void addFood(const string &mainCourse, int sides = 0, bool soup = false);
};

#endif // FOODORDER_H
