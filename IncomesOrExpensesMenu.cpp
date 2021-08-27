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
    incomeOrExpense.setOperationId((incomesOrExpensesFile.returnLastIdOperation() + 1)); //giveL
    cout << "Wybierz date operacji finansowej: ";
    incomeOrExpense.setDate(AuxiliaryMethods::loadLine()); //odniesienie do obiektu obslugujacego daty
    cout << "Wpisz czego dotyczy operacja finansowa: ";
    incomeOrExpense.setItem(AuxiliaryMethods::loadLine());
    cout << "Podaj kwote operacji finansowej: ";
    incomeOrExpense.setAmount(AuxiliaryMethods::loadNumber());

    return incomeOrExpense;
}
/*
int IncomesOrExpensesMenu::giveLastIdOperation()
{
    IncomeOrExpense incomeOrExpense;

    int idLastOperation = 0;
    if(incomesOrExpenses.empty() == true)
    {
        idLastOperation = 0;
        return idLastOperation;
    }else{
        incomeOrExpense = incomesOrExpenses.back();
        idLastOperation = incomeOrExpense.getOperationId();
        return idLastOperation;
    }
}
*/
void IncomesOrExpensesMenu::wypiszWydatki()  //metoda do testow
{
    for(int i = 0; i < incomesOrExpenses.size(); i++)
    {
        cout << incomesOrExpenses[i].getUserId() << endl;
        cout << incomesOrExpenses[i].getOperationId() << endl;
        cout << incomesOrExpenses[i].getDate() << endl;
        cout << incomesOrExpenses[i].getItem() << endl;
        cout << incomesOrExpenses[i].getAmount() << endl;
    }
}
