#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>

#include "Markup.h"

using namespace std;

class XmlFile
{
    string const NAME_OF_FILE;
public:
    XmlFile(string nameOfFile): NAME_OF_FILE(nameOfFile) {};
    bool fileIsEmpty();
    string returnFileName();
};

#endif

