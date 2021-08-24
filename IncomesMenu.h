#ifndef INCOMESMENU_H
#define INCOMESMENU_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Balance.h"
#include "AuxiliaryMethods.h"
#include "IncomesFile.h"

using namespace std;

class IncomesMenu
{
    const int ID_LOGGED_USER;
    vector <Balance> incomes;
    IncomesFile incomesFile;

    Balance giveNewIncomeData();
public:
    IncomesMenu(int idLoggedUser, string fileName): ID_LOGGED_USER(idLoggedUser), incomesFile(fileName)
    {
        incomes = incomesFile.loadIncomesFromFile();
    };
    void addIncome();

    void wypiszWydatki(); //metoda do testow
};

#endif INCOMESMENU_H
