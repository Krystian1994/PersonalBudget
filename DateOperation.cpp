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
        string date = "";
        int choice = 0;
        cin >> choice;
        cin.ignore();
        cin.sync();   //funkcje umozliwiajace zastosowanie getline.
        switch(choice)
        {
        case 1:
            date = getCurrentDate();
            return date;
        case 2:
            while(true)
            {
                cout << "Wprowadz date w formacie rrrr-mm-dd" << endl;
                cout << "Date nalezy wprowadzic w przedziale 2000-01-01 do " << returnCurrentYear() << '-' << returnCurrentMonth() << '-' << howManyDaysHaveMonth(returnCurrentYear(),returnCurrentMonth()) << endl;
                string selectedDateByUser = AuxiliaryMethods::loadLine();
                if(checkIntroducedDate(selectedDateByUser) == true)
                {
                    date = selectedDateByUser;
                    return date;
                }else{
                    cout << "Blad! Prosze wprowadzic date zgodnie z wytycznymi." << endl;
                    Sleep(1000);
                    system("cls");
                }
            }
        }
}
bool DateOperation::checkIntroducedDate(string date)
{
    string yearString = "";
    string monthString = "";
    string dayString = "";
    int yearInt = 0;
    int monthInt = 0;
    int daysInt = 0;
    int minYear = 2000;
    int currentYear = returnCurrentYear();
    int currentMonth = returnCurrentMonth();

    for(int i = 0; i < 4; i++){
        yearString += date[i];
    }
    yearInt = AuxiliaryMethods::convertionStringToInt(yearString);
    for(int i = 5; i < 7; i++){
        monthString += date[i];
    }
    monthInt = AuxiliaryMethods::convertionStringToInt(monthString);
    for(int i = 8; i <= 9; i++){
        dayString += date[i];
    }
    daysInt = AuxiliaryMethods::convertionStringToInt(dayString);

    if(date[4] == '-' && date[7] == '-'){
        if(yearInt >= minYear && yearInt <= currentYear){
            if(monthInt > 0 && monthInt <= 12){
                if(daysInt >= 1 && daysInt <= howManyDaysHaveMonth(yearInt,monthInt)){
                       if(yearInt == currentYear && monthInt == currentMonth && daysInt <= howManyDaysHaveMonth(currentYear,currentMonth)){
                           return true;
                       }else if(yearInt == currentYear && monthInt < currentMonth){
                           return true;
                       }else if(yearInt < currentYear){
                           return true;
                       }else {return false;}
                   }else{return false;}
            }else{return false;}
        }else{return false;}
    }else{return false;}
}
int DateOperation::howManyDaysHaveMonth(int year,int month)
{
    int month31[7] = {1,3,5,7,8,10,12};
    int month30[4] = {4,6,9,11};
    int february = 2;
    for(int i = 0; i < 7; i++)
    {
        if(month == month31[i])
        {
            return 31;
        }
    }
    for(int i = 0; i < 4; i++)
    {
        if(month == month30[i])
        {
            return 30;
        }
    }
    if(((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && (month == february))
    {
        return 29;
    }else {

        return 28;
    }
}
int DateOperation::returnCurrentYear()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    int year = 0;
    year = st.wYear;
    return year;
}
int DateOperation::returnCurrentMonth()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    int month = 0;
    month = st.wMonth;
    return month;
}
bool DateOperation::ifLoadDateIsCurrentMonth(string date)
{
    string currentDate = getCurrentDate();
    for(int i = 0; i < 7; i++) //sprawdzanie czy to obecny miesiac
    {
        if(date[i] != currentDate[i])
        {
            return false;
        }
    }
    return true;
}
bool DateOperation::ifLoadDateIsPreviousMonth(string date)
{
    int currentMonth = returnCurrentMonth();
    int currentYear = returnCurrentYear();
    string yearString = "";
    int yearInt = 0;
    string monthString = "";
    int monthInt = 0;
    for(int i = 0; i < 4; i++){
        yearString += date[i];
    }
    yearInt = AuxiliaryMethods::convertionStringToInt(yearString);
    for(int i = 5; i < 7; i++){
        monthString += date[i];
    }
    monthInt = AuxiliaryMethods::convertionStringToInt(monthString);

    if(yearInt == currentYear && currentMonth != 1 && (currentMonth - monthInt) == 1){
        return true;
    }else if((currentYear - yearInt) == 1 && currentMonth == 1 && monthInt == 12){
        return true;
    }else{
        return false;
    }
}
bool DateOperation::checkSelectedDates(string startingDate, string endingDate)
{
    if(checkIntroducedDate(startingDate) && checkIntroducedDate(startingDate) && startingDate <= endingDate){
           return true;
       }else{return false;};
}
