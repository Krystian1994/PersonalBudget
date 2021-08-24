#include "IncomesMenu.h"

void IncomesMenu::addIncome()
{
    Balance income;
    system("cls");

    income = giveNewIncomeData();
    incomes.push_back(income);

    incomesFile.addIncomeToFile(income);
    cout << endl << "Dochod zostal dodany" << endl << endl;
    system("pause");
}
Balance IncomesMenu::giveNewIncomeData()
{
    Balance income;

    income.setUserId(ID_LOGGED_USER);

    income.setOperationId(13);//income.setOperationId(...); stworzyc metode wyznaczajaca id operacji
    cout << "Wybierz date przychodu: ";
    income.setDate(AuxiliaryMethods::loadLine()); //odniesienie do obiektu obslugujacego daty

    cout << "Wpisz czego dotyczy przychod: ";
    income.setItem(AuxiliaryMethods::loadLine());

    cout << "Podaj wartosc przychodu: ";
    income.setAmount(AuxiliaryMethods::loadNumber());

    return income;
}

void IncomesMenu::wypiszWydatki()  //metoda do testow
{
    for(int i = 0; i < incomes.size(); i++)
    {
        cout << incomes[i].getUserId() << endl;
        cout << incomes[i].getOperationId() << endl;
        cout << incomes[i].getDate() << endl;
        cout << incomes[i].getItem() << endl;
        cout << incomes[i].getAmount() << endl;
    }
}
