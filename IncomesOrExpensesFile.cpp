#include "IncomesOrExpensesFile.h"

void IncomesOrExpensesFile::addIncomeOrExpenseToFile(IncomeOrExpense incomeOrExpense)
{
    CMarkup xml;
    bool fileExists = xml.Load(returnFileName());
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Operations");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Operation");
    xml.IntoElem();
    xml.AddElem(NAME_OF_ID_OPERATION,incomeOrExpense.getOperationId());
    xml.AddElem("userId",incomeOrExpense.getUserId());
    xml.AddElem("date",incomeOrExpense.getDate());
    xml.AddElem("item",incomeOrExpense.getItem());
    xml.AddElem("amount",incomeOrExpense.getAmount());

    xml.Save(FILE_NAME);

    idLastOperation++;
}
vector <IncomeOrExpense> IncomesOrExpensesFile::loadIncomesOrExpensesFromFile(int idLoggedUser)
{
    vector <IncomeOrExpense> incomesOrExpenses;
    IncomeOrExpense incomeOrExpense;

    CMarkup xml;
    bool fileExists = xml.Load(returnFileName());

    xml.ResetPos(); // top of document
    xml.FindElem(); // ORDER element is root
    xml.IntoElem(); // inside ORDER
    while ( xml.FindElem("Operation") )
    {
        xml.FindChildElem("NAME_OF_ID_OPERATION");
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
    idLastOperation = giveLastIdOperation(incomesOrExpenses);

    return incomesOrExpenses;
}
int IncomesOrExpensesFile::giveLastIdOperation(vector <IncomeOrExpense> incomesOrExpenses)
{
    IncomeOrExpense incomeOrExpense;
    int idOperation = 0;
    if(incomesOrExpenses.empty())
    {
        return idOperation;
    }else{
        incomeOrExpense = incomesOrExpenses.back();
        idOperation = incomeOrExpense.getOperationId();
        return idOperation;
    }
}
int IncomesOrExpensesFile::returnLastIdOperation()
{
    return idLastOperation;
}
