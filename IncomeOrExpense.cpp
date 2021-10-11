#include "IncomeOrExpense.h"

void IncomeOrExpense::setUserId(int newUserId)
{
    userId = newUserId;
}
void IncomeOrExpense::setOperationId(int newOperationId)
{
    operationId = newOperationId;
}
void IncomeOrExpense::setDate(string newDate)
{
    date = newDate;
}
void IncomeOrExpense::setItem(string newItem)
{
    item = newItem;
}
void IncomeOrExpense::setAmount(double newAmount)
{
    amount = newAmount;
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
