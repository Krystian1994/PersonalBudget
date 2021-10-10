#ifndef INCOMESOREXPENSESFILE_H
#define INCOMESOREXPENSESFILE_H

#include <iostream>
#include <string>
#include <vector>

#include "IncomeOrExpense.h"
#include "Markup.h"
#include "XmlFile.h"
#include "AuxiliaryMethods.h"

using namespace std;

class IncomesOrExpensesFile: public XmlFile
{
    int idLastOperation;
    const string FILE_NAME;
    const string NAME_OF_ID_OPERATION;
public:
    IncomesOrExpensesFile(string fileName, string nameOfIdOperation)
    : FILE_NAME(fileName), XmlFile(fileName), NAME_OF_ID_OPERATION(nameOfIdOperation)
    {
        idLastOperation = 0;
    };
    void addIncomeOrExpenseToFile(IncomeOrExpense incomeOrExpense);
    vector <IncomeOrExpense> loadIncomesOrExpensesFromFile(int idLoggedUser);
    int returnLastIdOperation();
};

#endif INCOMESOREXPENSESFILE_H
