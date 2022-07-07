#include "AuxiliaryMethods.h"


string AuxiliaryMethods::convertIntToString(int number) {

    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}


char AuxiliaryMethods::loadChar() {

    string input = "";
    char oneChar  = {0};

    while (true) {
        getline(cin, input);

        if (input.length() == 1) {
            oneChar = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return oneChar;
}


string AuxiliaryMethods::loadLine() {

    string input = "";
    getline(cin, input);
    return input;
}


string AuxiliaryMethods::changeFirstLetterForUpperCaseAndOthersForLowerCase(string tekst) {

    if (!tekst.empty()) {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}


int AuxiliaryMethods::convertStringToInt(string number) {

    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}


string AuxiliaryMethods::getCurrentDate() {

    string currentDate;
    SYSTEMTIME SystemTime;

    GetSystemTime( & SystemTime );
    currentDate = convertIntToString(SystemTime.wYear);
    if(SystemTime.wMonth < 10) {
        currentDate += "-0" + convertIntToString(SystemTime.wMonth);
    } else {
        currentDate += '-' + convertIntToString(SystemTime.wMonth);
    }
    if(SystemTime.wDay < 10) {
        currentDate += "-0" + convertIntToString(SystemTime.wDay);
    } else {
        currentDate += '-' + convertIntToString(SystemTime.wDay);
    }
    return currentDate;
}


float AuxiliaryMethods::convertStringToFloat(string number) {
    float numberFloat;
    numberFloat = stof(number);
    setprecision(2);

    return numberFloat;
}


string AuxiliaryMethods::convertFloatToString(float number){

ostringstream ss;
ss << number;
string str(ss.str());

return str;

}


string AuxiliaryMethods::changeFormatDateToDateWithHyphens(int date) {

    string dateWithHyphens = convertIntToString(date);
    dateWithHyphens.insert(4,"-");
    dateWithHyphens.insert(7,"-");

    return dateWithHyphens;

}


int AuxiliaryMethods::changeFormatDateToInt(string dateStr) {

    int date;

    dateStr.erase(4,1);
    dateStr.erase(6,1);

    date = convertStringToInt(dateStr);

    return date;


}


bool AuxiliaryMethods::checkIsYearIsLeapYear(int year) {

    if((year%4==0 && year%100!=0) || year%400==0) {
        return true;
    }
    return false;
}


string AuxiliaryMethods::replaceCommaToDot(string number) {

    for(int i = 0; i < number.length(); i++) {

        if(number[i] == ',') {
            number[i] = '.';
        } else {
            continue;
        }
    }
    return number;
}

int AuxiliaryMethods::getMonth(int date)
{
    int month;

    month = date % 10000;
    month = date / 100;

    return month;
}
