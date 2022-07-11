#include "Expenses.h"


int Expenses::getId() {
    return id;
}
int Expenses::getUserId() {
    return userId;
}
int Expenses::getDate() {
    return date;
}
string Expenses::getItem() {
    return item;
}
float Expenses::getAmount() {
    return amount;
}


void Expenses::setId(int newId) {

    id = newId;
}

void Expenses::setUserId(int newUserId) {

    userId = newUserId;
}
void Expenses::setDate(int newDate) {

    date = newDate;
}
void Expenses::setItem(string newItem) {

    item = newItem;
}
void Expenses::setAmount(float newAmount) {

    amount = newAmount;
}
