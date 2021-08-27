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
{
    cout << "Dochody : "<< endl;
    income.wypiszWydatki();
    cout << "Wydatki : "<< endl;
    expense.wypiszWydatki();

}
void BalanceMenu::showBalancePreviousMonth()
{

}
void BalanceMenu::showBalanceSelectedPeriod()
{

}
