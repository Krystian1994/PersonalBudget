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
float AuxiliaryMethods::loadNumber()
{
    string numberString = loadLine();
    for(int i = 0; i < numberString.size(); i++)
    {
        if(numberString[i] == ',')
        {
            char dot = '.';
            numberString[i] = dot;
        }
    }
    stringstream ss;
    double number;
    ss << numberString;
    ss >> number;

    return number;
}
