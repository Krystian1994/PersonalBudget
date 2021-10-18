#include "UsersFile.h"

void UsersFile::addUserToFile(User user)
{
    CMarkup xml;
    bool fileExists = xml.Load(getFileName());

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("id", user.getId());
    xml.AddElem("name", user.getName());
    xml.AddElem("surname", user.getSurname());
    xml.AddElem("login", user.getLogin());
    xml.AddElem("password", user.getPassword());
    xml.Save("users.xml");
}
vector <User> UsersFile::loadUsersFromFile()
{
    vector <User> users;
    User user;
    CMarkup xml;
    bool fileExists = xml.Load(getFileName());
    xml.ResetPos(); // top of document
    xml.FindElem(); // ORDER element is root
    xml.IntoElem(); // inside ORDER

    while ( xml.FindElem("User") ) {
        xml.FindChildElem( "id" );
        user.setId(AuxiliaryMethods::convertionStringToInt(xml.GetChildData()));
        xml.FindChildElem( "name" );
        user.setName(xml.GetChildData());
        xml.FindChildElem( "surname" );
        user.setSurname(xml.GetChildData());
        xml.FindChildElem( "login" );
        user.setLogin(xml.GetChildData());
        xml.FindChildElem( "password" );
        user.setPassword(xml.GetChildData());
        users.push_back(user);
    }

    return users;
}
void UsersFile::removeDataInFile()
{
    CMarkup xml;
    bool fileExists = xml.Load(getFileName());
    xml.ResetMainPos();

    while(xml.FindElem()) {
        xml.RemoveElem();
    }

    xml.Save("users.xml");
}
void UsersFile::saveAllUsersToFile(vector <User> &users)
{
    for(int i = 0; i <  users.size(); i++) {
        CMarkup xml;
        bool fileExists = xml.Load(getFileName());

        if (!fileExists) {
            xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
            xml.AddElem("Users");
        }

        xml.FindElem();
        xml.IntoElem();
        xml.AddElem("User");
        xml.IntoElem();
        xml.AddElem("id", users[i].getId());
        xml.AddElem("name", users[i].getName());
        xml.AddElem("surname", users[i].getSurname());
        xml.AddElem("login", users[i].getLogin());
        xml.AddElem("password", users[i].getPassword());
        xml.Save("users.xml");
    }
}

