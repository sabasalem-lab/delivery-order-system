//Saba Salem

#include <iostream> //Allows use of cout, cin, etc.
#include <iomanip> //Allows formatting numbers, like setprecision(2) for money
#include "InvalidInput.h"
#include "DeliveryOrder.h" //Base class (abstract)
#include "BobaOrder.h"
#include "FoodOrder.h"
#include "Account.h"

using namespace std;

// applyDiscount: returns the discounted payment (totalBalance * factor)
//DeliveryOrder *order -> A pointer to the base class → allows polymorphism
// because (VIPdiscount() can behave differently for BobaOrder/FoodOrder)
//const Account &acct -> Passed by reference to avoid copying, and const means we don’t modify the account
float applyDiscount(DeliveryOrder *order, const Account &acct) {
    float total = order->getTotalBalance();
    string status = acct.getStatus();

    if (status == "Owner") {
        // Owner gets 90% off -> pays 10% -> return total * 0.1
        return total * 0.1f;
    } else if (status == "VIP") {
        // VIP -> use dynamic VIPdiscount factor from the order
        float factor = order->VIPdiscount(); //Different for boba vs food → this is polymorphism
        return total * factor;
    } else {
        // Regular -> no discount
        return total;
    }
}

int main() {
    // create accounts
    const Account stu("Stuart", "Owner"); //stu is const because Owner cannot change status
    Account kev("Kevin", "VIP");
    Account bob("Bob"); // constructor auto-assigns "Regular"

    // pointer for polymorphism
    DeliveryOrder *orderPtr = nullptr;
    //Because DeliveryOrder is abstract — we can only point to child objects.

    // set cout formatting for money
    cout << fixed << setprecision(2);

    // 1. Kevin placing order
    cout << "Kevin is placing order.\n";
    BobaOrder kevOrder("Kevin", "04/20/2024", "123-456-0000", 10.4f, "M Tea");

    try {
        kevOrder.addDrink("Green Tea Latte");                     // default boba true, count 1
        kevOrder.addDrink("Brown Sugar Pearl Milk", false);      // no boba
        kevOrder.addDrink("Brown Sugar Boba Milk", false, 2);    // two, no boba
        kevOrder.addDrink("Iron Goddess");                       // not served -> throws
    } catch (const InvalidInput &e) {
        e.reason();//prints the exception message
        cout << "Not serving requested drinks. Drink order ignored.\n\n";
    }

    kevOrder.receipt(); //This prints: name, date, phone ,order balance,(plus drinks count from BobaOrder)
    cout << "Balance: $" << kevOrder.getTotalBalance() << "\n"; //Balance before discount
    //Uses DeliveryOrder’s formula: (orderBalance * (1 + taxRate)) + miles * deliveryRate
    //Polymorphic discount: VIP uses BobaOrder’s version of VIPdiscount
    orderPtr = &kevOrder;
    cout << "Discounted Balance: $" << applyDiscount(orderPtr, kev) << "\n\n\n";

    // 2. Stuart placing order
    cout << "Stuart is placing order.\n";
    FoodOrder stuOrder("Stuart", "04/20/2024", "123-456-1111", 25.5f, "Tavern Green");

    try {
        stuOrder.addFood("Thick Cauliflower Steaks", 1, true);  // one side, soup
        stuOrder.addFood("Organic Scottish Salmon");            // no side, no soup
        stuOrder.addFood("Rack of Lamb", 0, true);              // soup only
    } catch (const InvalidInput &e) {
        e.reason();
        cout << "Not serving requested food. Food order ignored.\n\n";
    }

    stuOrder.receipt();
    cout << "Balance: $" << stuOrder.getTotalBalance() << "\n";
    orderPtr = &stuOrder;
    cout << "Discounted Balance: $" << applyDiscount(orderPtr, stu) << "\n\n\n";

    // 3. Bob checking Stuart's order
    cout << "Bob decided to log in to his account and see whether he can afford ordering the same order as Stuart.\n";
    // reuse the same Stuart order object
    stuOrder.receipt();
    cout << "Balance: $" << stuOrder.getTotalBalance() << "\n";
    orderPtr = &stuOrder;
    cout << "Discounted Balance: $" << applyDiscount(orderPtr, bob) << "\n";
    cout << "Bob upset, cancelling order :(\n\n";

    // total orders placed
    cout << "Total order placed: " << DeliveryOrder::getOrderCount() << "\n\n";

    // destructors will be called automatically for stack objects in reverse order of construction
    return 0;
    //Destructors print messages as required.
}
