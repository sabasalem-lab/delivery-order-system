//Saba Salem

#include "Account.h"

Account::Account(const string& user, const string& stat)
{
    username = user;
    status = stat;
}

Account::~Account()
{
    cout << "Account removed.\n";
    //This will be printed at the end of the program when accounts are deleted.
}

string Account::getStatus() const
{
    return status;
}
//Returns: "Owner" ,"VIP" ,"Regular" Used inside applyDiscount().

