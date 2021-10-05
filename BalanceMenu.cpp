#include "BalanceMenu.h"

void BalanceMenu::addIncome()
{
    system("cls");
    income.addIncomeOrExpense();
    cout << endl << "Dochod zostal dodany." << endl << endl;
    system("pause");
}
void BalanceMenu::addExpense()
{
    system("cls");
    expense.addIncomeOrExpense();
    cout << endl << "Wydatek zostal dodany." << endl << endl;
    system("pause");
}
void BalanceMenu::showBalanceCurrentMonth()
{ //do testow
    cout << "Dochody : "<< endl;
    income.wypiszWydatki();
    cout << "Wydatki : "<< endl;
    expense.wypiszWydatki();

    system("pause");
}
void BalanceMenu::showBalancePreviousMonth()
{
    cout << "W trakcie tworzenia" << endl;
}
void BalanceMenu::showBalanceSelectedPeriod()
{
    cout << "W trakcie tworzenia" << endl;
}
