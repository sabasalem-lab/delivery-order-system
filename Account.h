//Saba Salem

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>
using namespace std;

class Account
{
private: //These cannot be accessed directly outside the class.
    string username;
    string status;   // "Regular", "VIP", or "Owner"

public:
    // Constructor
    // use const + & because its the best way to pass large objects like string
    //Copying long strings = SLOW
    //string& user , This takes the string by reference, no copy
    // using const meaning: I take your string by reference (no copy), but I promise I will not modify it
    Account(const string& user, const string& stat = "Regular");

    // Destructor
    ~Account(); // will print Account removed.

    // Getter
    string getStatus() const;
};

#endif
