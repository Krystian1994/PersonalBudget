#ifndef INCOMESOREXPENSESMENU_H
#define INCOMESOREXPENSESMENU_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "IncomeOrExpense.h"
#include "AuxiliaryMethods.h"
#include "IncomesOrExpensesFile.h"
#include "DateOperation.h"

using namespace std;

class IncomesOrExpensesMenu
{
    const int ID_LOGGED_USER;
    vector <IncomeOrExpense> incomesOrExpenses;
    IncomesOrExpensesFile incomesOrExpensesFile;
    IncomeOrExpense giveNewIncomeOrExpenseData();
    void sortingVector();
public:
    IncomesOrExpensesMenu(int idLoggedUser, string fileName, string nameOfIdOperation)
    :ID_LOGGED_USER(idLoggedUser), incomesOrExpensesFile(fileName,nameOfIdOperation)
    {
        incomesOrExpenses = incomesOrExpensesFile.loadIncomesOrExpensesFromFile(ID_LOGGED_USER);// ID_LOGGED_USER jako argument metody
    }
    void addIncomeOrExpense();
    double showBalanceCurrentMonth();
    double showBalancePreviousMonth();
    double showBalanceSelectedPeriod(string startingDate,string endingDate);
};

#endif INCOMESOREXPENSESMENU_H
