#include "Incomes.h"


int Incomes::getIncomesId() {
    return incomesId;
}
int Incomes::getUserId() {
    return userId;
}
int Incomes::getDate() {
    return date;
}
string Incomes::getItem() {
    return item;
}
float Incomes::getAmount() {
    return amount;
}


void Incomes::setIncomesId(int newIncomesId) {

    incomesId = newIncomesId;
}

void Incomes::setUserId(int newUserId) {

    userId = newUserId;
}
void Incomes::setDate(int newDate) {

    date = newDate;
}
void Incomes::setItem(string newItem) {

    item = newItem;
}
void Incomes::setAmount(float newAmount) {

    amount = newAmount;
}
