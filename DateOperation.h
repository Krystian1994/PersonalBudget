#ifndef DATEOPERATION_H
#define DATEOPERATION_H

#include <iostream>
#include <windows.h>
#include <winbase.h>

#include "AuxiliaryMethods.h"

using namespace std;

class DateOperation
{
    static string getCurrentDate();
public:
    static string getSelectedDate();
};

#endif DATEOPERATION_H
