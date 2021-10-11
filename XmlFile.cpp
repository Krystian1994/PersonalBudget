#include "XmlFile.h"

bool XmlFile::fileIsEmpty()
{
    CMarkup xml;
    bool fileExists = xml.Load(returnFileName());

    if (!fileExists) {
        return false;
    }

    return true;
}
string XmlFile::returnFileName()
{
    return NAME_OF_FILE;
}
