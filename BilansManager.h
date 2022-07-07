#ifndef BILANSMANAGER_H
#define BILANSMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "IncomesManager.h"
#include "ExpensesManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class BilansManager {


vector <Expenses> expensesVector;
vector <Incomes> incomesVector;

public:

void displayBilansCurrentMonth();
void displayBilansPreviousMonth();
void displayBilansSelectedPeriod();

};

#endif

