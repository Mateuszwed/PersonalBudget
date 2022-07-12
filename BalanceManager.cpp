#include "BalanceManager.h"


bool BalanceManager::checkDateIsNotHigherThanCurrentDate(int date) {

    int dateYear = getYear(date);
    int dateMonth = getMonth(date);
    int currentDate = getCurrentDateInteger();
    int currentDateYear = getYear(currentDate);
    int currentDateMonth = getMonth(currentDate);

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
    int dateInt = changeFormatDateToInt(date);
    int dateMonth = getMonth(dateInt);
    int dateYear = getYear(dateInt);
    int dateDay = getDay(dateInt);

    switch(dateMonth) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if((dateDay < 1) || (dateDay > 31)) {
            return false;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if((dateDay < 1) || (dateDay > 30)) {
            return false;
        }
        break;
    case 2:
        if(!checkIsYearIsLeapYear(dateYear)) {

            if((dateDay < 1) || (dateDay > 28)) {
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
            return changeFormatDateToInt(date);
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
            return changeFormatDateToInt(date);
        } else {
            cout << "Podales zly format daty." << endl;
            ifCorrect = true;
        }
    }
}


string BalanceManager::changeFormatDateToDateWithHyphens(int date) {

    string dateWithHyphens = AuxiliaryMethods::convertIntToString(date);
    dateWithHyphens.insert(4,"-");
    dateWithHyphens.insert(7,"-");

    return dateWithHyphens;

}


int BalanceManager::changeFormatDateToInt(string dateStr) {

    int date;

    dateStr.erase(4,1);
    dateStr.erase(6,1);

    date = AuxiliaryMethods::convertStringToInt(dateStr);

    return date;


}


bool BalanceManager::checkIsYearIsLeapYear(int year) {

    if((year%4==0 && year%100!=0) || year%400==0) {
        return true;
    } else {
        return false;
    }
}


string BalanceManager::replaceCommaToDot(string number) {

    for(int i = 0; i < number.length(); i++) {

        if(number[i] == ',') {
            number[i] = '.';
        } else {
            continue;
        }
    }
    return number;
}


int BalanceManager::getMonth(int date) {

    int month = 0;

    month = date % 10000;
    month = month / 100;

    return month;
}


int BalanceManager::getDay(int date) {

    int day = 0;

    day = date % 100;

    return day;
}


int BalanceManager::getYear(int date) {

    int year = 0;

    year = date / 10000;

    return year;
}

int BalanceManager::getCurrentDateInteger() {

    string currentDate = "";
    int date = 0;
    SYSTEMTIME SystemTime;

    GetSystemTime( & SystemTime );
    currentDate = AuxiliaryMethods::convertIntToString(SystemTime.wYear);
    if(SystemTime.wMonth < 10) {
        currentDate += "0" + AuxiliaryMethods::convertIntToString(SystemTime.wMonth);
    } else {
        currentDate += AuxiliaryMethods::convertIntToString(SystemTime.wMonth);
    }
    if(SystemTime.wDay < 10) {
        currentDate += "0" + AuxiliaryMethods::convertIntToString(SystemTime.wDay);
    } else {
        currentDate += AuxiliaryMethods::convertIntToString(SystemTime.wDay);
    }

    date = AuxiliaryMethods::convertStringToInt(currentDate);

    return date;
}

string BalanceManager::getCurrentDate() {

    string currentDate;
    SYSTEMTIME SystemTime;

    GetSystemTime( & SystemTime );
    currentDate = AuxiliaryMethods::convertIntToString(SystemTime.wYear);
    if(SystemTime.wMonth < 10) {
        currentDate += "-0" + AuxiliaryMethods::convertIntToString(SystemTime.wMonth);
    } else {
        currentDate += '-' + AuxiliaryMethods::convertIntToString(SystemTime.wMonth);
    }
    if(SystemTime.wDay < 10) {
        currentDate += "-0" + AuxiliaryMethods::convertIntToString(SystemTime.wDay);
    } else {
        currentDate += '-' + AuxiliaryMethods::convertIntToString(SystemTime.wDay);
    }
    return currentDate;
}
