#ifndef INCOMES_H
#define INCOMES_H

#include <iostream>

using namespace std;

class Incomes {

int incomesId;
int userId;
int date;
string item;
float amount;


public:

    int getIncomesId();
    int getUserId();
    int getDate();
    string getItem();
    float getAmount();

    void setIncomesId(int newIncomesId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);
};

#endif


