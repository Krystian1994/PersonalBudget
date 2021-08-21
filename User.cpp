#include "User.h"

int User::setId(int newId)
{
    if(newId > 0)
    {
        id = newId;
        return id;
    }
}
string User::setName(string newName)
{
    name = newName;
    return name;
}
string User::setSurname(string newSurname)
{
    surname = newSurname;
    return surname;
}
string User::setLogin(string newLogin)
{
    login = newLogin;
    return login;
}
string User::setPassword(string newPassword)
{
    password = newPassword;
    return password;
}
int User::getId()
{
    return id;
}
string User::getName()
{
    return name;
}
string User::getSurname()
{
    return surname;
}
string User::getLogin()
{
    return login;
}
string User::getPassword()
{
    return password;
}
