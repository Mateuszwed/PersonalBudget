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
bool checkIsYearIsLeapYear(int year);
bool checkFormatDate(string date);
string replaceCommaToDot(string number);
int getMonth(int date);
int getDay(int date);
int getYear(int date);
int getCurrentDateInteger();
string getCurrentDate();
static string changeFormatDateToDateWithHyphens(int date);
static int changeFormatDateToInt(string dateStr);

};


#endif

