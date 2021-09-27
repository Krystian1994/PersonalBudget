#include <iostream>

#include "UsersMenu.h"
#include "XmlFile.h"
#include "UsersFile.h"
#include <windows.h>

#include "BalanceMenu.h"
#include "AuxiliaryMethods.h"
#include "DateOperation.h"

using namespace std;

int main()
{
    /*
    XmlFile file("users.xml");
    cout << file.returnFileName() << endl;
    cout << file.fileIsEmpty() << endl;
    system("pause");
    */
    /*
    UsersMenu user("users.xml");
    user.userRegistration();
    user.userRegistration();

    user.loginUser();
    user.changePasswordOfLoggedUser();
    user.logOutUser();

    //user.wypiszUzytkownikow();
    */
    BalanceMenu balance(1,"incomes.xml","expenses.xml");

    balance.addIncome();
    //balance.addIncome();
    //balance.addExpense();

    balance.showBalanceCurrentMonth();

    //DateOperation dateOperation;


    return 0;
}
