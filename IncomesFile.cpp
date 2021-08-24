#include "IncomesFile.h"

void IncomesFile::addIncomeToFile(Balance income)
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
    xml.AddElem("incomeId",income.getOperationId());
    xml.AddElem("userId",income.getUserId());
    xml.AddElem("date",income.getDate());
    xml.AddElem("item",income.getItem());
    xml.AddElem("amount",income.getAmount());

    xml.Save("incomes.xml");
}
vector <Balance> IncomesFile::loadIncomesFromFile()
{
    vector <Balance> incomes;
    Balance income;

    CMarkup xml;
    bool fileExists = xml.Load(returnFileName());

    xml.ResetPos(); // top of document
    xml.FindElem(); // ORDER element is root
    xml.IntoElem(); // inside ORDER
    while ( xml.FindElem("Income") )
    {
        xml.FindChildElem("incomeId");
        income.setOperationId(AuxiliaryMethods::convertionStringToInt(xml.GetChildData()));

        xml.FindChildElem("userId");
        income.setUserId(AuxiliaryMethods::convertionStringToInt(xml.GetChildData()));

        xml.FindChildElem("date");
        income.setDate(xml.GetChildData());

        xml.FindChildElem("item");
        income.setItem(xml.GetChildData());

        xml.FindChildElem("amount");
        income.setAmount(AuxiliaryMethods::convertionStringToDouble(xml.GetChildData()));

        incomes.push_back(income);
    }
    return incomes;
}
