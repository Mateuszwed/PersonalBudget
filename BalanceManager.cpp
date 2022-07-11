#include "BalanceManager.h"


bool BalanceManager::checkDateIsNotHigherThanCurrentDate(int date) {

    int dateYear = AuxiliaryMethods::getYear(date);
    int dateMonth = AuxiliaryMethods::getMonth(date);
    int currentDate = AuxiliaryMethods::getCurrentDateInteger();
    int currentDateYear = AuxiliaryMethods::getYear(currentDate);
    int currentDateMonth = AuxiliaryMethods::getMonth(currentDate);

    if(dateYear < 2000) {
        return false;
    } else if (dateYear > currentDateYear) {
        return false;
    } else if (dateYear == currentDateYear) {
        if (dateMonth > currentDateMonth) {
            return false;
        }
    }
    return true;
}


bool BalanceManager::checkCorrectEnterDate(string date) {

    if((date.length() < 10) || (date.length() > 10)) {
        return false;
    }
    int dateInt = AuxiliaryMethods::changeFormatDateToInt(date);
    int dateMonth = AuxiliaryMethods::getMonth(dateInt);
    int dateYear = AuxiliaryMethods::getYear(dateInt);

    switch(dateMonth) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if((dateMonth < 1) || (dateMonth > 31)) {
            return false;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if((dateMonth < 1) || (dateMonth > 30)) {
            return false;
        }
        break;
    case 2:
        if(!AuxiliaryMethods::checkIsYearIsLeapYear(dateYear)) {

            if((dateMonth < 1) || (dateMonth > 28)) {
                return false;
            }
        }
        break;
    default:
        return false;
    }

    return true;

}


int BalanceManager::getFirstDateFromUser() {
    string date;
    bool ifCorrect = true;
    while(ifCorrect) {
        cout << "Data od: ";
        date = AuxiliaryMethods::loadLine();
        if(checkCorrectEnterDate(date)) {
            return AuxiliaryMethods::changeFormatDateToInt(date);
        } else {
            cout << "Podales zly format daty." << endl;
            ifCorrect = true;
        }
    }
}


int BalanceManager::getSecondDateFromUser() {
    string date = "";
    bool ifCorrect = true;
    while(ifCorrect) {
        cout << "Data do: ";
        date = AuxiliaryMethods::loadLine();
        if(checkCorrectEnterDate(date)) {
            return AuxiliaryMethods::changeFormatDateToInt(date);
        } else {
            cout << "Podales zly format daty." << endl;
            ifCorrect = true;
        }
    }
}

