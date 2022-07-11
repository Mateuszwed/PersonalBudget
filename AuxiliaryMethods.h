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
    static string replaceCommaToDot(string number);

};

#endif
