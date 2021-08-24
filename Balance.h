#ifndef BALANCE_H
#define BALANCE_H

#include <iostream>

using namespace std;

class Balance
{
    int userId;
    int operationId;
    string date;
    string item;
    double amount;
public:
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


#endif BALANCE_H
