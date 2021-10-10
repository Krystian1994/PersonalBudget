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
    double balance = 0;
    cout << "Przychody w obecnym miesiacu: "<< endl << endl;
    double incomesSum = income.showBalanceCurrentMonth();
    cout << endl << "Wydatki w obecnym miesiacu: "<< endl;
    double expensesSum = expense.showBalanceCurrentMonth();
    cout << endl << "Suma przychodow w obecnym miesiacu wynosi " << incomesSum << endl;
    cout << endl << "Suma wydatkow w obecnym miesiacu wynosi " << expensesSum << endl;
    balance = incomesSum + expensesSum;
    cout << endl << "Bilans w obecnym miesiacu wynosi " << balance << endl;
    system("pause");
}
void BalanceMenu::showBalancePreviousMonth()
{
    system("cls");
    double balance = 0;
    cout << "Przychody w poprzednim miesiacu: "<< endl << endl;
    double incomesSum = income.showBalancePreviousMonth();
    cout << "Wydatki w poprzednim mesiacu: "<< endl;
    double expensesSum = expense.showBalancePreviousMonth();
    cout << endl << "Suma przychodow w poprzednim miesiacu wynosi " << incomesSum << endl;
    cout << endl << "Suma wydatkow w poprzednim miesiacu wynosi " << expensesSum << endl;
    balance = incomesSum + expensesSum;
    cout << endl << "Bilans w poprzednim miesiacu wynosi " << balance << endl;
    system("pause");

}
void BalanceMenu::showBalanceSelectedPeriod()
{
    system("cls");
    string startingDate="";
    string endingDate="";
    cout << "Wprowadz ramy czasowe w formacie rrrr-mm-dd" << endl;
    cout << "Od ";
    startingDate = AuxiliaryMethods::loadLine();
    cout << " do ";
    endingDate = AuxiliaryMethods::loadLine();
    if(DateOperation::checkSelectedDates(startingDate,endingDate)){
        double balance = 0;
        cout << "Przychody w wybranym okresie: "<< endl << endl;
        double incomesSum = income.showBalanceSelectedPeriod(startingDate,endingDate);
        cout << "Wydatki w wybranym okresie: "<< endl;
        double expensesSum = expense.showBalanceSelectedPeriod(startingDate,endingDate);
        cout << endl << "Suma przychodow w wybranym okresie wynosi " << incomesSum << endl;
        cout << endl << "Suma wydatkow w wybranym okresie wynosi " << expensesSum << endl;
        balance = incomesSum + expensesSum;
        cout << endl << "Bilans w wybranym okresie wynosi " << balance << endl;
    }else{
        cout << "Wprowadzono nieprawidlowe dane." << endl;
    }
    system("pause");
}
