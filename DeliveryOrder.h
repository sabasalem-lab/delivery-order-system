//Saba Salem

#ifndef DELIVERYORDER_H
#define DELIVERYORDER_H

#include <iostream>
#include <string>
using namespace std;

class DeliveryOrder {
private: // These cannot be changed by inherited classes.
    string name;
    string date;
    string phone;
    float miles;

    // static members
    /* meaning : Shared by all DeliveryOrder objects.
                Exists once in the program.
                Must be defined in DeliveryOrder.cpp. */
    static int orderCount;
    static const float taxRate;
    static const float deliveryRate;

protected: /*Protected means:
            BobaOrder and FoodOrder can access it directly.
            Good, because they add items and increase this. */
    float orderBalance;

public:
    // Constructor
    DeliveryOrder(const string& name,
                  const string& date,
                  const string& phone,
                  float miles);

    // Destructor, must be virtual because We will delete objects through a base class pointer
    // (DeliveryOrder* ptr = new BobaOrder)
    virtual ~DeliveryOrder();

    // Functions
    virtual void receipt() const;     // NOT pure virtual
    // Children (BobaOrder, FoodOrder) will override it to add 1 extra line.
    float getTotalBalance() const;    // constant , orderBalance * (1 + taxRate) + miles * deliveryRate
    static int getOrderCount();       // static, Returns how many orders were made.
    virtual float VIPdiscount() const = 0; // PURE virtual, This makes DeliveryOrder abstract.
};

#endif

