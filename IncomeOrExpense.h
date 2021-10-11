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

    void setUserId(int newUserId);
    void setOperationId(int newOperationId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);
    int getUserId();
    int getOperationId();
    string getDate();
    string getItem();
    double getAmount();
};

#endif
