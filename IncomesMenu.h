#ifndef INCOMESMENU_H
#define INCOMESMENU_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Balance.h"
#include "AuxiliaryMethods.h"

using namespace std;

class IncomesMenu
{
    const int ID_LOGGED_USER;
    vector <Balance> incomes;
    Balance giveNewIncomeData();
public:
    IncomesMenu(int idLoggedUser) : ID_LOGGED_USER(idLoggedUser){};
    void addIncome();

    void wypiszWydatki(); //metoda do testow
};

#endif INCOMESMENU_H
