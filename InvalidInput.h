//Saba Salem

#ifndef INVALIDINPUT_H //this starts an include gaurd, meaning if this file is included more than once, it wont be duplicated.
#define INVALIDINPUT_H //defines the gaurd, now the compiler knows that if it sees INVALIDINPUT_H again, it should skip the file.

#include <iostream> // need it for cout
#include <string>
using namespace std;

class InvalidInput {
private: // only class methods can access these
    const string message; // its a constant member, you cannot assign to it inside the constructor body
                            //you must initialize it in the initialization list
                            // you are telling C++:
                            //This value can never change after the object is created.
                            //Because it's const, you must give it a value at the moment the object is constructed — not later.
public:
    // constructor declaration
    InvalidInput(const string& input)
        : message ("Invalid Input \"" + input + "\".\n"){} // this is the initialization list

    // use initialization list because the message is constant
    // the escape \" is needed to place quotation marks inside the string.
    void reason() const{
        cout << message;} // prints the stored error text
        //const means this function does not change any class variables

    };

#endif // INVALIDINPUT_H
