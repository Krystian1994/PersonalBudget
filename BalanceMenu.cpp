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
    system("cls");
    int balance = 0;
    cout << "Przychody : "<< endl;
    int incomesSum = income.wypiszWydatki();
    cout << "Wydatki : "<< endl;
    int expenseSum = expense.wypiszWydatki();
    cout << endl << "Suma przychodow wynosi " << incomesSum << endl;
    cout << endl << "Suma wydatkow wynosi " << expenseSum << endl;
    balance = incomesSum + expenseSum;
    cout << endl << "Bilans w obecnym miesiacu wynosi " << balance << endl;
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
