#ifndef BALANCEMENU_H
#define BALANCEMENU_H

#include <iostream>

#include "IncomesOrExpensesMenu.h"
#include "DateOperation.h"
#include "AuxiliaryMethods.h"

using namespace std;

class BalanceMenu
{
    IncomesOrExpensesMenu income;
    IncomesOrExpensesMenu expense;
public:
    BalanceMenu(int idLoggedUser, string incomeFileName, string expenseFileName)
        : income(idLoggedUser, incomeFileName, "incomeId"), expense(idLoggedUser, expenseFileName, "expenseId") {}
    void addIncome();
    void addExpense();
    void showBalanceCurrentMonth();
    void showBalancePreviousMonth();
    void showBalanceSelectedPeriod();
};

#endif
