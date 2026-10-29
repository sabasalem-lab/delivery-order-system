//Saba Salem

#ifndef BOBAORDER_H
#define BOBAORDER_H

#include "DeliveryOrder.h"
#include "InvalidInput.h"
#include <string>
#include <iostream>
using namespace std;

class BobaOrder : public DeliveryOrder {
private:
    string shopName;
    int drinksCount;

public:
    BobaOrder(const string &name,
              const string &date,
              const string &phone,
              float miles,
              const string &shopName);

    ~BobaOrder();

    void receipt() const override;

    float VIPdiscount() const override;

    // addDrink: drink name, addBoba defaults to true, count defaults to 1
    void addDrink(const string &drinkName, bool addBoba = true, int count = 1);
};

#endif // BOBAORDER_H
