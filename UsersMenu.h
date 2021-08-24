#ifndef USERSMENU_H
#define USERSMENY_H

#include <iostream>
#include <vector>

#include "User.h"
#include "UsersFile.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UsersMenu
{
    int idLoggedUser;
    vector <User> users;
    UsersFile usersFile;

    User giveNewUserData();
    bool userNameExist(string login);
    int loadIdNewUser();
public:
    UsersMenu(string nameOfUsersFile): usersFile(nameOfUsersFile)
    {
        idLoggedUser = 0;
        users = usersFile.loadUsersFromFile();
    };
    void userRegistration();
    int loginUser();
    void changePasswordOfLoggedUser();
    void logOutUser();
    bool userIsLogged();
    int loadIdLoggedUser();

    void wypiszUzytkownikow(); //metoda do testow
};





#endif


