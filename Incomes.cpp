#include "Incomes.h"


int Incomes::getId() {
    return id;
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


void Incomes::setId(int newId) {

    id = newId;
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
