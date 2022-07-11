#ifndef EXPENSES_H
#define EXPENSES_H

#include <iostream>

using namespace std;

class Expenses {

int id;
int userId;
int date;
string item;
float amount;


public:

    int getId();
    int getUserId();
    int getDate();
    string getItem();
    float getAmount();

    void setId(int newId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);
};

#endif

