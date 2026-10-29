# Delivery Order System

A C++ console application that models boba and restaurant delivery orders. Customers have accounts with different tiers (Regular, VIP, Owner), and each order's final price depends on the order type and the account tier. Built to practice object-oriented design in C++.

## Features

- **Abstract base class** `DeliveryOrder` holds shared order data (name, date, phone, distance) and the pricing formula
- **Two order types** that inherit from it: `BobaOrder` (drinks) and `FoodOrder` (main courses, sides, soup)
- **Polymorphic VIP discounts:** each order type decides its own discount through an overridden `VIPdiscount()` function
- **Account tiers** in the `Account` class: Regular (no discount), VIP (discount depends on the order), Owner (pays 10% of the total)
- **Custom exception** `InvalidInput` is thrown when someone orders an item that isn't on the menu
- **Static members** keep track of the total number of orders placed and store the tax and delivery rates

## How pricing works

`Total = order balance × 1.09 (9% tax) + miles × $2.00 delivery`

| Order type | VIP discount |
|---|---|
| Boba | 3+ drinks: 5% off, 6+ drinks: 10% off, 11+ drinks: 20% off |
| Food | Order over $20: 5% off, over $30: 10% off, over $50: 20% off |

## Menu

**Boba:** Green Tea Latte $5.80, Brown Sugar Boba Milk $7.80, Brown Sugar Pearl Milk $9.80 (extra boba +$1.00 per drink)

**Food:** Thick Cauliflower Steaks $15, Organic Scottish Salmon $23, Rack of Lamb $38, Grilled Lobster Risotto $46 (soup +$5, each side +$6)

## Project structure

| File | Purpose |
|---|---|
| `main.cpp` | Creates accounts and orders, applies discounts, prints receipts |
| `DeliveryOrder.h/.cpp` | Abstract base class |
| `BobaOrder.h/.cpp` | Boba order subclass |
| `FoodOrder.h/.cpp` | Food order subclass |
| `Account.h/.cpp` | Account with a status tier |
| `InvalidInput.h` | Custom exception class |

## How to run

With g++:

```
g++ -std=c++11 -Wall *.cpp -o delivery-order-system
./delivery-order-system
```

On Windows, run `delivery-order-system.exe` instead. You can also open `FinalProjectQuiz.cbp` in Code::Blocks and press Build and Run.

## Sample output

```
Kevin is placing order.
Invalid Input "Iron Goddess".
Not serving requested drinks. Drink order ignored.

Order Detail:
	Name: Kevin
	Date: 04/20/2024
	Phone: 123-456-0000
	Order Balance: $32.20
	Drinks Count: 4
Balance: $55.90
Discounted Balance: $53.10

Stuart is placing order.
Order Detail:
	Name: Stuart
	Date: 04/20/2024
	Phone: 123-456-1111
	Order Balance: $92.00
	Food Count: 3
Balance: $151.28
Discounted Balance: $15.13
```

## Concepts demonstrated

Inheritance, abstract classes and pure virtual functions, polymorphism through base-class pointers, virtual destructors, exception handling with a custom class, static members, initialization lists, const-correctness, and multi-file C++ projects.

## Author

Saba Salem, Computer Science student at Irvine Valley College
[LinkedIn](https://www.linkedin.com/in/saba-salem) · [Portfolio](https://sabasalem-lab.github.io)
