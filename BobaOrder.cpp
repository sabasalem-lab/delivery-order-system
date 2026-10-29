//Saba Salem

#include "BobaOrder.h"
// This file must know:, BobaOrder class definition, DeliveryOrder base class (included inside), InvalidInput (included inside header)

BobaOrder::BobaOrder(const string &name,
                     const string &date,
                     const string &phone,
                     float miles,
                     const string &shopName)
    //Initialization list:
    : DeliveryOrder(name, date, phone, miles), shopName(shopName), drinksCount(0)
    //Calls base class constructor, Initializes shopName from parameter, drinksCount = 0 at start
    /*DeliveryOrder(name, date, phone, miles) -> This initializes:
DeliveryOrder::name, DeliveryOrder::date, DeliveryOrder::phone, DeliveryOrder::miles, DeliveryOrder::orderBalance = 0, increments orderCount*/
{
}
BobaOrder::~BobaOrder() {
    cout << "BobaOrder destroyed.\n";
    /*What happens when a BobaOrder object is deleted?
BobaOrder destructor runs → prints message
Then DeliveryOrder destructor runs → prints "DeliveryOrder destroyed."*/
}
//receipt() override
void BobaOrder::receipt() const {
    // reuse base receipt (DRY)
    DeliveryOrder::receipt();
    cout << "\tDrinks Count: " << drinksCount << endl;
    /*It first prints the base order information
Then adds BobaOrder-specific detail (drinks count)
DRY Principle (Don’t Repeat Yourself)
We avoid duplicating the code inside DeliveryOrder::receipt
This is exactly how subclass receipts should be built.*/
}
//VIPdiscount() override
float BobaOrder::VIPdiscount() const {
    if (drinksCount > 10) return 0.8f;
    if (drinksCount > 5)  return 0.9f; //drinksCount = 8 → return 0.9f → pay 90% of total
    if (drinksCount > 2)  return 0.95f;
    return 1.0f;
}

void BobaOrder::addDrink(const string &drinkName, bool addBoba, int count) {
    if (count <= 0) return; // nothing to add

    float pricePer = 0.0f;
    if (drinkName == "Green Tea Latte") {
        pricePer = 5.8f;
    } else if (drinkName == "Brown Sugar Boba Milk") {
        pricePer = 7.8f;
    } else if (drinkName == "Brown Sugar Pearl Milk") {
        pricePer = 9.8f;
    } else {
        // not on the menu -> throw
        throw InvalidInput(drinkName);
    }

    float extraBoba = addBoba ? 1.0f : 0.0f; //if addBoba = true → extraBoba = 1 , else = 0
    float totalCost = (pricePer + extraBoba) * static_cast<float>(count);

    drinksCount += count;
    orderBalance += totalCost; //orderBalance is protected Because it belongs to the base class, but subclasses need to modify it.
}
