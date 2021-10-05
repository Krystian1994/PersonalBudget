#ifndef INCOMEOREXPENSE_H
#define INCOMEOREXPENSE_H

#include <iostream>

using namespace std;

class IncomeOrExpense
{
    int userId;
    int operationId;
    string item;
    double amount;
public:
    string date;

    int setUserId(int newUserId);
    int setOperationId(int newOperationId);
    string setDate(string newDate);
    string setItem(string newItem);
    double setAmount(double newAmount);

    int getUserId();
    int getOperationId();
    string getDate();
    string getItem();
    double getAmount();
};


#endif INCOMEOREXPENSE_H
