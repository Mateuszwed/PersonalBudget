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


string AuxiliaryMethods::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst) {

    if (!tekst.empty())
    {
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

int AuxiliaryMethods::wczytajLiczbeCalkowita(){

    string wejscie = "";
    int liczba = 0;

    while (true)
    {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}
