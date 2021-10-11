#include "UsersMenu.h"

void UsersMenu::userRegistration()
{
    User user = giveNewUserData();
    users.push_back(user);
    usersFile.addUserToFile(user);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}
User UsersMenu::giveNewUserData()
{
    User user;
    user.setId(loadIdNewUser());
    cout << "Podaj imie: ";
    user.setName(AuxiliaryMethods::loadLine());
    cout << "Podaj nazwisko: ";
    user.setSurname(AuxiliaryMethods::loadLine());

    do {
        cout << "Podaj login: ";
        user.setLogin(AuxiliaryMethods::loadLine());
    } while (userNameExist(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    user.setPassword(AuxiliaryMethods::loadLine());
    return user;
}
int UsersMenu::loadIdNewUser()
{
    return (users.empty()) ? 1 : users.back().getId() + 1;
}
bool UsersMenu::userNameExist(string login)
{
    for(int i = 0; i < users.size(); i++) {
        if(login == users[i].getLogin()) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }

    return false;
}
int UsersMenu::loginUser()
{
    User user;
    string login = "", password = "";
    cout << "Podaj login: ";
    login = AuxiliaryMethods::loadLine();

    for(int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            for (int tryNumber = 3; tryNumber > 0; tryNumber--) {
                cout << "Podaj haslo. Pozostalo prob: " << tryNumber << ": ";
                password = AuxiliaryMethods::loadLine();

                if (users[i].getPassword() == password) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    idLoggedUser = users[i].getId();
                    system("pause");
                    return idLoggedUser;
                }
            }

            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return idLoggedUser;
        }
    }

    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return idLoggedUser;
}
void UsersMenu::changePasswordOfLoggedUser()
{
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods::loadLine();

    for(int i = 0; i < users.size(); i++) {
        if (users[i].getId() == idLoggedUser) {
            system("pause");
            users[i].setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }

    usersFile.removeDataInFile();
    usersFile.saveAllUsersToFile(users);
}
void UsersMenu::logOutUser()
{
    idLoggedUser = 0;
}
int UsersMenu::loadIdLoggedUser()
{
    return idLoggedUser;
}
bool UsersMenu::userIsLogged()
{
    return (idLoggedUser > 0);
}
