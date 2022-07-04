#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods {

public:

    static string convertIntToString(int number);
    static char loadChar();
    static string loadLine();
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static int convertStringToInt(string number);
    static int wczytajLiczbeCalkowita();

};

#endif
