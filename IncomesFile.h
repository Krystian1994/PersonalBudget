#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>

#include "Balance.h"
#include "Markup.h"
#include "XmlFile.h"
#include "AuxiliaryMethods.h"

using namespace std;

class IncomesFile: public XmlFile
{
public:
    IncomesFile(string fileName): XmlFile(fileName){};
    void addIncomeToFile(Balance income);
    vector <Balance> loadIncomesFromFile();
};

#endif INCOMESFILE_H
