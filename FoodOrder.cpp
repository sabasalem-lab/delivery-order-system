//Saba Salem

#include "FoodOrder.h"

FoodOrder::FoodOrder(const string &name,
                     const string &date,
                     const string &phone,
                     float miles,
                     const string &restaurantName)
    : DeliveryOrder(name, date, phone, miles), restaurantName(restaurantName), foodCount(0)
{
}

FoodOrder::~FoodOrder() {
    cout << "FoodOrder destroyed.\n";
}

void FoodOrder::receipt() const {
    DeliveryOrder::receipt();
    cout << "\tFood Count: " << foodCount << endl;
}

float FoodOrder::VIPdiscount() const {
    if (orderBalance > 50.0f) return 0.8f;
    if (orderBalance > 30.0f) return 0.9f;
    if (orderBalance > 20.0f) return 0.95f;
    return 1.0f;
}

void FoodOrder::addFood(const string &mainCourse, int sides, bool soup) {
    float price = 0.0f;
    if (mainCourse == "Thick Cauliflower Steaks") {
        price = 15.0f;
    } else if (mainCourse == "Rack of Lamb") {
        price = 38.0f;
    } else if (mainCourse == "Organic Scottish Salmon") {
        price = 23.0f;
    } else if (mainCourse == "Grilled Lobster Risotto") {
        price = 46.0f;
    } else {
        throw InvalidInput(mainCourse);
    }

    float extra = 0.0f;
    if (soup) extra += 5.0f;
    if (sides > 0) extra += 6.0f * static_cast<float>(sides);

    float total = price + extra;

    foodCount += 1;
    orderBalance += total;
}
