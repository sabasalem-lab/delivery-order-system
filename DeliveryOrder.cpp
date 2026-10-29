//Saba Salem

#include "DeliveryOrder.h" //This gives CPP access to:, class declaration, member variable names, function prototypes, This file implements those functions.

// initialize static members, static members must be defined outside the class exactly once in a .cpp file.
int DeliveryOrder::orderCount = 0;
const float DeliveryOrder::taxRate = 0.09f;
const float DeliveryOrder::deliveryRate = 2.0f;

DeliveryOrder::DeliveryOrder(const string &name,
                             const string &date,
                             const string &phone,
                             float miles)
    //The part after the colon is the initialization list:
    : name(name), date(date), phone(phone), miles(miles), orderBalance(0.0f)
    //Why use initialization list? Required for const members, Required for reference members, Faster & cleaner
{
    ++orderCount;
}

DeliveryOrder::~DeliveryOrder() {
    cout << "DeliveryOrder destroyed.\n";
}

void DeliveryOrder::receipt() const {
    cout << "Order Detail:" << "\n";
    cout << "\tName: " << name << "\n";
    cout << "\tDate: " << date << "\n";
    cout << "\tPhone: " << phone << "\n";
    //    //Subclasses (BobaOrder / FoodOrder) override this but also call base version
    cout << "\tOrder Balance: $" << orderBalance << endl;
    //Uses static constants, Uses dynamic orderBalance
}

float DeliveryOrder::getTotalBalance() const {
    return orderBalance * (1.0f + taxRate) + miles * deliveryRate;

}

int DeliveryOrder::getOrderCount() {
    return orderCount;
    //static Because orderCount belongs to the class, not individual objects.
}
