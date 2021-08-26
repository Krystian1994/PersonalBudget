#ifndef INCOMESOREXPENSESFILE_H
#define INCOMESOREXPENSESFILE_H

#include <iostream>
#include <vector>

#include "IncomeOrExpense.h"
#include "Markup.h"
#include "XmlFile.h"
#include "AuxiliaryMethods.h"

using namespace std;

class IncomesOrExpensesFile: public XmlFile
{
    const string FILE_NAME;
public:
    IncomesOrExpensesFile(string fileName): FILE_NAME(fileName), XmlFile(fileName){};
    void addIncomeOrExpenseToFile(IncomeOrExpense incomeOrExpense);
    vector <IncomeOrExpense> loadIncomesOrExpensesFromFile();
};

#endif INCOMESOREXPENSESFILE_H
