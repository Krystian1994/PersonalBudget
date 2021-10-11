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
double AuxiliaryMethods::loadNumber()
{
    string numberString = loadLine();

    for(int i = 0; i < numberString.size(); i++) {
        if(numberString[i] == ',') {
            char dot = '.';
            numberString[i] = dot;
        }
    }

    double number = convertionStringToDouble(numberString);
    return number;
}
double AuxiliaryMethods::convertionStringToDouble(string numberString)
{
    stringstream ss;
    double number;
    ss << numberString;
    ss >> number;

    return number;
}
string AuxiliaryMethods::convertionIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
char AuxiliaryMethods::loadCharacter()
{
    string enter = "";
    char character  = {0};

    while (true) {
        getline(cin, enter);

        if (enter.length() == 1) {
            character = enter[0];
            break;
        }

        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }

    return character;
}
