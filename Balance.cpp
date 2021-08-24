#include "Balance.h"

int Balance::setUserId(int newUserId)
{
    userId = newUserId;
    return userId;
}
int Balance::setOperationId(int newOperationId)
{
    operationId = newOperationId;
    return operationId;
}
string Balance::setDate(string newDate)
{
    date = newDate;
    return date;
}
string Balance::setItem(string newItem)
{
    item = newItem;
    return item;
}
float Balance::setAmount(float newAmount)
{
    amount = newAmount;
    return amount;
}
string Balance::getDate()
{
    return date;
}
string Balance::getItem()
{
    return item;
}
float Balance::getAmount()
{
    return amount;
}
int Balance::getOperationId()
{
    return operationId;
}
int Balance::getUserId()
{
    return userId;
}
