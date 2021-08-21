#include "AuxiliaryMethods.h"

string AuxiliaryMethods::loadLine()
{
    string enter = "";
    getline(cin, enter);
    return enter;
}
int AuxiliaryMethods::convertionStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}
