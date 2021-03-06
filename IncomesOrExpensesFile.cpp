#include "IncomesOrExpensesFile.h"

void IncomesOrExpensesFile::addIncomeOrExpenseToFile(IncomeOrExpense incomeOrExpense)
{
    CMarkup xml;
    bool fileExists = xml.Load(FILE_NAME);

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Operations");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Operation");
    xml.IntoElem();
    xml.AddElem("userId", incomeOrExpense.getUserId());
    xml.AddElem(NAME_OF_ID_OPERATION, incomeOrExpense.getOperationId());
    xml.AddElem("date", incomeOrExpense.getDate());
    xml.AddElem("item", incomeOrExpense.getItem());
    xml.AddElem("amount", to_string(incomeOrExpense.getAmount()));

    xml.Save(FILE_NAME);

    idLastOperation++;
}
vector <IncomeOrExpense> IncomesOrExpensesFile::loadIncomesOrExpensesFromFile(int idLoggedUser)
{
    vector <IncomeOrExpense> incomesOrExpenses;
    IncomeOrExpense incomeOrExpense;
    CMarkup xml;
    xml.Load(FILE_NAME);
    xml.FindElem("Operations");
    xml.IntoElem();

    while (xml.FindElem("Operation")) {
        xml.IntoElem();
        xml.FindElem("userId");

        if(atoi(MCD_2PCSZ(xml.GetData())) == idLoggedUser) {
            incomeOrExpense.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem(NAME_OF_ID_OPERATION);
            incomeOrExpense.setOperationId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("date");
            incomeOrExpense.setDate(xml.GetData());
            xml.FindElem("item");
            incomeOrExpense.setItem(xml.GetData());
            xml.FindElem("amount");
            incomeOrExpense.setAmount(AuxiliaryMethods::convertionStringToDouble(xml.GetData()));
            incomesOrExpenses.push_back(incomeOrExpense);
        }

        xml.FindElem(NAME_OF_ID_OPERATION);
        incomeOrExpense.setOperationId(atoi(MCD_2PCSZ(xml.GetData())));
        idLastOperation = incomeOrExpense.getOperationId();
        xml.OutOfElem();
    }

    return incomesOrExpenses;
}
int IncomesOrExpensesFile::returnLastIdOperation()
{
    return idLastOperation;
}
