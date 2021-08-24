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
    float amount;
public:
    int setUserId(int newUserId);
    int setOperationId(int newOperationId);
    string setDate(string newDate);
    string setItem(string newItem);
    float setAmount(float newAmount);

    int getUserId();
    int getOperationId();
    string getDate();
    string getItem();
    float getAmount();
};


#endif BALANCE_H
