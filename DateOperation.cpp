#include "DateOperation.h"

string DateOperation::getCurrentDate()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    int year = 0;
    int month = 0;
    int day = 0;
    year = st.wYear;
    month = st.wMonth;
    day = st.wDay;

    string yearString = AuxiliaryMethods::convertionIntToString(year);
    string monthString = AuxiliaryMethods::convertionIntToString(month);
    string dayString = AuxiliaryMethods::convertionIntToString(day);
    string currentDate = "";
    if(month >= 10 && day >= 10)
    {
        currentDate = yearString + "-" + monthString + "-" + dayString;
    }else if(month >= 10 && day < 10)
    {
        currentDate = yearString + "-" + monthString + "-0" + dayString;
    }else if(month < 10 && day >= 10)
    {
        currentDate = yearString + "-0" + monthString + "-" + dayString;
    }else if(month < 10 && day < 10)
    {
        currentDate = yearString + "-0" + monthString + "-0" + dayString;
    }

    return currentDate;
}
string DateOperation::getSelectedDate()
{
    cout << endl <<  "Aby wybrac dzisiejsza date, wybierz: 1" << endl;
    cout << "Aby wpisac date recznie, wybierz: 2" << endl;
    int choice = 0;
    string date = "";
    cin >> choice;
    switch (choice)
    {
    case 1:
        date = getCurrentDate();
        break;
    case 2:
        string selectedDateByUser = AuxiliaryMethods::loadLine();//dodac warunek sprawdzajacy poprawnosc wpisanej daty
        date = selectedDateByUser;
        break;
    }

    return date;
}
