#include "IncomesOrExpensesFile.h"

void IncomesOrExpensesFile::addIncomeOrExpenseToFile(IncomeOrExpense incomeOrExpense)
{
    CMarkup xml;
    bool fileExists = xml.Load(returnFileName());
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("incomeId",incomeOrExpense.getOperationId());
    xml.AddElem("userId",incomeOrExpense.getUserId());
    xml.AddElem("date",incomeOrExpense.getDate());
    xml.AddElem("item",incomeOrExpense.getItem());
    xml.AddElem("amount",incomeOrExpense.getAmount());

    xml.Save(FILE_NAME);
}
vector <IncomeOrExpense> IncomesOrExpensesFile::loadIncomesOrExpensesFromFile()
{
    vector <IncomeOrExpense> incomesOrExpenses;
    IncomeOrExpense incomeOrExpense;

    CMarkup xml;
    bool fileExists = xml.Load(returnFileName());

    xml.ResetPos(); // top of document
    xml.FindElem(); // ORDER element is root
    xml.IntoElem(); // inside ORDER
    while ( xml.FindElem("Income") )
    {
        xml.FindChildElem("incomeId");
        incomeOrExpense.setOperationId(AuxiliaryMethods::convertionStringToInt(xml.GetChildData()));

        xml.FindChildElem("userId");
        incomeOrExpense.setUserId(AuxiliaryMethods::convertionStringToInt(xml.GetChildData()));

        xml.FindChildElem("date");
        incomeOrExpense.setDate(xml.GetChildData());

        xml.FindChildElem("item");
        incomeOrExpense.setItem(xml.GetChildData());

        xml.FindChildElem("amount");
        incomeOrExpense.setAmount(AuxiliaryMethods::convertionStringToDouble(xml.GetChildData()));

        incomesOrExpenses.push_back(incomeOrExpense);
    }
    return incomesOrExpenses;
}
