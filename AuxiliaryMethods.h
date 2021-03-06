#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods
{
public:
    static double changeToNegativeNumber(double number);
    static string loadLine();
    static double loadNumber();
    static int convertionStringToInt(string number);
    static double convertionStringToDouble(string numberString);
    static string convertionIntToString(int number);
    static char loadCharacter();
};

#endif
