#ifndef INCOMESOREXPENSESMENU_H
#define INCOMESOREXPENSESMENU_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "IncomeOrExpense.h"
#include "AuxiliaryMethods.h"
#include "IncomesOrExpensesFile.h"

using namespace std;

class IncomesOrExpensesMenu
{
    const int ID_LOGGED_USER;
    vector <IncomeOrExpense> incomesOrExpenses;

    IncomesOrExpensesFile incomesOrExpensesFile;

    IncomeOrExpense giveNewIncomeOrExpenseData();
    int giveLastIdOperation();
public:
    IncomesOrExpensesMenu(int idLoggedUser, string fileName): ID_LOGGED_USER(idLoggedUser), incomesOrExpensesFile(fileName)
    {
        incomesOrExpenses = incomesOrExpensesFile.loadIncomesOrExpensesFromFile();
    };
    void addIncomeOrExpense();

    void wypiszWydatki(); //metoda do testow
};

#endif INCOMESOREXPENSESMENU_H
