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


string AuxiliaryMethods::changeFirstLetterForUpperCaseAndOthersForLowerCase(string text) {

    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}


int AuxiliaryMethods::convertStringToInt(string number) {

    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
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

