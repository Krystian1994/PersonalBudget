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

    string name;
    cout << "Podaj imie: ";
    name = AuxiliaryMethods::loadLine();
    user.setName(name);

    string surname;
    cout << "Podaj nazwisko: ";
    surname = AuxiliaryMethods::loadLine();
    user.setSurname(surname);

    string login;
    do
    {
        cout << "Podaj login: ";
        login = AuxiliaryMethods::loadLine();
        user.setLogin(login);
    }while (userNameExist(user.getLogin()) == true);

    string password;
    cout << "Podaj haslo: ";
    password = AuxiliaryMethods::loadLine();
    user.setPassword(password);

    return user;
}
int UsersMenu::loadIdNewUser()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}
bool UsersMenu::userNameExist(string login)
{
    for(int i = 0; i < users.size(); i++)
    {
        if(login == users[i].getLogin())
        {
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
    login = AuxiliaryMethods::loadLine());

    for(int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            for (int tryNumber = 3; tryNumber > 0; tryNumber--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << tryNumber << ": ";
                password = AuxiliaryMethods::loadLine();
                if (users[i].getPassword() == password)
                {
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
    for(int i = 0; i < users.size(); i++)
    {
        if (users[i].getId() == idLoggedUser)
        {
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
    if(idLoggedUser > 0)
        return true;
    else
        return false;
}
void UsersMenu::wypiszUzytkownikow()
{
    for(int i = 0; i < users.size(); i++)
    {
        cout << users[i].getId() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getSurname() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword()<< endl;
    }
}
