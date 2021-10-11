#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>

#include "User.h"
#include "Markup.h"
#include "XmlFile.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UsersFile: public XmlFile
{
public:
    UsersFile(string fileName): XmlFile(fileName) {};
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void removeDataInFile();
    void saveAllUsersToFile(vector <User> &users);
};

#endif
