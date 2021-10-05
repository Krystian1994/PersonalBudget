#include "PersonalBudget.h"

void PersonalBudget::registration()
{
    usersMenu.userRegistration();
}
void PersonalBudget::login()
{
    usersMenu.loginUser();
    if(usersMenu.userIsLogged())
    {
        balanceMenu = new BalanceMenu(usersMenu.loadIdLoggedUser(),INCOME_FILE_NAME,EXPENSE_FILE_NAME);
    }
}
bool PersonalBudget::isTheUserLoggedIn()
{
    usersMenu.userIsLogged();
}
void PersonalBudget::addIncome()
{
    if(usersMenu.userIsLogged()){
        balanceMenu->addIncome();
    }else{
        cout << "Aby dodac dochod nalezy sie zalogowac." << endl;
        system("pause");
    }
}
void PersonalBudget::addExpense()
{
    if(usersMenu.userIsLogged()){
        balanceMenu->addExpense();
    }else{
        cout << "Aby dodac wydatek nalezy sie zalogowac." << endl;
        system("pause");
    }
}
void PersonalBudget::balanceFromCurrentMonth()
{
    balanceMenu->showBalanceCurrentMonth();
}
void PersonalBudget::balanceFromPreviousMonth()
{
    balanceMenu->showBalancePreviousMonth();
}
void PersonalBudget::balanceFromSelectedTerm()
{
    balanceMenu->showBalanceSelectedPeriod();
}
void PersonalBudget::changePassword()
{
    usersMenu.changePasswordOfLoggedUser();
}
void PersonalBudget::logOutUser()
{
    usersMenu.logOutUser();
    delete balanceMenu;
    balanceMenu = NULL;
}
