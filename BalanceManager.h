#ifndef BILANSMANAGER_H
#define BILANSMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "AuxiliaryMethods.h"

using namespace std;

class BalanceManager {


public:

bool checkDateIsNotHigherThanCurrentDate(int date);
bool checkCorrectEnterDate(string date);

int getFirstDateFromUser();
int getSecondDateFromUser();

};


#endif

