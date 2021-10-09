#include "IncomesOrExpensesMenu.h"

void IncomesOrExpensesMenu::addIncomeOrExpense()
{
    IncomeOrExpense incomeOrExpense;
    incomeOrExpense = giveNewIncomeOrExpenseData();
    incomesOrExpenses.push_back(incomeOrExpense);
    incomesOrExpensesFile.addIncomeOrExpenseToFile(incomeOrExpense);
}
IncomeOrExpense IncomesOrExpensesMenu::giveNewIncomeOrExpenseData()
{
    IncomeOrExpense incomeOrExpense;

    incomeOrExpense.setUserId(ID_LOGGED_USER);
    incomeOrExpense.setOperationId(incomesOrExpensesFile.returnLastIdOperation()+1);// dodaj id operacji

    cout << "Wybierz date operacji finansowej: ";
    incomeOrExpense.setDate(DateOperation::getSelectedDate());
    cout << "Wpisz czego dotyczy operacja finansowa: ";
    incomeOrExpense.setItem(AuxiliaryMethods::loadLine());
    cout << "Podaj kwote operacji finansowej: ";
    incomeOrExpense.setAmount(AuxiliaryMethods::loadNumber());

    return incomeOrExpense;
}
void IncomesOrExpensesMenu::sortingVector()
{
    sort(incomesOrExpenses.begin(),incomesOrExpenses.end(), [](const IncomeOrExpense &a, const IncomeOrExpense &b)
    {return a.date < b.date;});
}
int IncomesOrExpensesMenu::showBalanceCurrentMonth()  //metoda do testow
{
    sortingVector();
    string date="";
    double balance = 0;
    for(int i = 0; i < incomesOrExpenses.size(); i++)
    {
        date = incomesOrExpenses[i].getDate();
        if(DateOperation::ifLoadDateIsCurrentMonth(date))
        {
            cout << incomesOrExpenses[i].getUserId() << endl;
            cout << incomesOrExpenses[i].getOperationId() << endl;
            cout << incomesOrExpenses[i].getDate() << endl;
            cout << incomesOrExpenses[i].getItem() << endl;
            cout << incomesOrExpenses[i].getAmount() << endl;
            cout << "-----------------" << endl;
            balance += incomesOrExpenses[i].getAmount();
        }
    }
    return balance;
}
int IncomesOrExpensesMenu::showBalancePreviousMonth()
{
    sortingVector();
    string date="";
    double balance = 0;
    for(int i = 0; i < incomesOrExpenses.size(); i++)
    {
        date = incomesOrExpenses[i].getDate();
        if(DateOperation::ifLoadDateIsPreviousMonth(date))
        {
            cout << incomesOrExpenses[i].getUserId() << endl;
            cout << incomesOrExpenses[i].getOperationId() << endl;
            cout << incomesOrExpenses[i].getDate() << endl;
            cout << incomesOrExpenses[i].getItem() << endl;
            cout << incomesOrExpenses[i].getAmount() << endl;
            cout << "-----------------" << endl;
            balance += incomesOrExpenses[i].getAmount();
        }
    }
    return balance;
}
int IncomesOrExpensesMenu::showBalanceSelectedPeriod(string startingDate,string endingDate)
{
    sortingVector();
    string date="";
    double balance = 0;
    for(int i = 0; i < incomesOrExpenses.size(); i++)
    {
        date = incomesOrExpenses[i].getDate();
        if(startingDate <= date && date <= endingDate)
        {
            cout << incomesOrExpenses[i].getUserId() << endl;
            cout << incomesOrExpenses[i].getOperationId() << endl;
            cout << incomesOrExpenses[i].getDate() << endl;
            cout << incomesOrExpenses[i].getItem() << endl;
            cout << incomesOrExpenses[i].getAmount() << endl;
            cout << "-----------------" << endl;
            balance += incomesOrExpenses[i].getAmount();
        }
    }
    return balance;
}
