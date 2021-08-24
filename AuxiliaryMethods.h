#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods
{
public:
    static string loadLine();
    static float loadNumber();
    static int convertionStringToInt(string number);
};
#endif
