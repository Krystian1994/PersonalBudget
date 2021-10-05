#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UsersMenu.h"
#include "BalanceMenu.h"

using namespace std;

class PersonalBudget
{
    UsersMenu usersMenu;
    BalanceMenu *balanceMenu;
    const string INCOME_FILE_NAME;
    const string EXPENSE_FILE_NAME;
public:
    PersonalBudget(string nameOfUsersFile,string incomeFileName, string expenseFileName)
    : usersMenu(nameOfUsersFile), INCOME_FILE_NAME(incomeFileName), EXPENSE_FILE_NAME(expenseFileName)
    {
        balanceMenu = NULL;
    };
    ~PersonalBudget()
    {
        delete balanceMenu;
        balanceMenu = NULL;
    };
    void registration();
    void login();
    bool isTheUserLoggedIn();
    void addIncome();
    void addExpense();
    void balanceFromCurrentMonth();
    void balanceFromPreviousMonth();
    void balanceFromSelectedTerm();
    void changePassword();
    void logOutUser();
};





#endif
