#include "IncomeOrExpense.h"

int IncomeOrExpense::setUserId(int newUserId)
{
    userId = newUserId;
    return userId;
}
int IncomeOrExpense::setOperationId(int newOperationId)
{
    operationId = newOperationId;
    return operationId;
}
string IncomeOrExpense::setDate(string newDate)
{
    date = newDate;
    return date;
}
string IncomeOrExpense::setItem(string newItem)
{
    item = newItem;
    return item;
}
double IncomeOrExpense::setAmount(double newAmount)
{
    amount = newAmount;
    return amount;
}
string IncomeOrExpense::getDate()
{
    return date;
}
string IncomeOrExpense::getItem()
{
    return item;
}
double IncomeOrExpense::getAmount()
{
    return amount;
}
int IncomeOrExpense::getOperationId()
{
    return operationId;
}
int IncomeOrExpense::getUserId()
{
    return userId;
}
