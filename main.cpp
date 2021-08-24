#include <iostream>

#include "UsersMenu.h"
#include "XmlFile.h"
#include "UsersFile.h"
#include <windows.h>

#include "IncomesMenu.h"

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
    IncomesMenu incomes(1);
    incomes.addIncome();
    incomes.wypiszWydatki();
    incomes.addIncome();
    incomes.wypiszWydatki();
    incomes.addIncome();
    incomes.wypiszWydatki();

    return 0;
}
