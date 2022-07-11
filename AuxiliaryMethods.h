#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <windows.h>
#include <iomanip>

using namespace std;

class AuxiliaryMethods {


public:

    static string convertIntToString(int number);
    static char loadChar();
    static string loadLine();
    static string changeFirstLetterForUpperCaseAndOthersForLowerCase(string text);
    static int convertStringToInt(string number);
    static string getCurrentDate();
    static int getCurrentDateInteger();
    static float convertStringToFloat(string number);
    static string convertFloatToString(float number);
    static string changeFormatDateToDateWithHyphens(int date);
    static int changeFormatDateToInt(string dateStr);
    static bool checkIsYearIsLeapYear(int year);
    static bool checkFormatDate(string date);
    static string replaceCommaToDot(string number);
    static int getMonth(int date);
    static int getDay(int date);
    static int getYear(int date);
};

#endif
