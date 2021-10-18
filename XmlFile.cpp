#include "XmlFile.h"

bool XmlFile::fileIsEmpty()
{
    CMarkup xml;
    bool fileExists = xml.Load(getFileName());

    if (!fileExists) {
        return false;
    }

    return true;
}
string XmlFile::getFileName()
{
    return NAME_OF_FILE;
}
