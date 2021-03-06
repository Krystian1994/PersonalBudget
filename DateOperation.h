#ifndef DATEOPERATION_H
#define DATEOPERATION_H

#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <sstream>
#include <algorithm>
#include <windows.h>
#include <winbase.h>

#include "AuxiliaryMethods.h"

using namespace std;

class DateOperation
{
    static string getCurrentDate();
    static bool checkIntroducedDate(string date);
    static int howManyDaysHaveMonth(int year, int month);
    static int getCurrentYear();
    static int getCurrentMonth();
    static bool yearIsLeap(int year);
public:
    static string getSelectedDate();
    static bool dateIsCurrentMonth(string date);
    static bool dateIsPreviousMonth(string date);
    static bool checkSelectedDates(string startingDate, string endingDate);
};

#endif
