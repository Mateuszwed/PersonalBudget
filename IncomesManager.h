#ifndef INCOMESMANAGER_H
#define INCOMESMANAGER_H

#include <iostream>
#include <vector>

#include "Incomes.h"
#include "FileWithIncomes.h"


using namespace std;

class IncomesManager {

    const int LOGGED_IN_USER_ID;
    vector <Incomes> incomesVector;
    FileWithIncomes fileWithIncomes;
    Incomes getDataNewIncomes(int loggedInUserId, int lastIdIncomes);
    bool checkCorrectEnterAmount(string amount);
    float getAmountFromUser();
    bool compareTwoDates(int dateTab[], int currentDateTab[]);
    void convertDateToArray(int dateArray[], string date);
    string getItemFromUser();

public:

    IncomesManager(string fileNameWithIncomes, int loggedInUserId) : LOGGED_IN_USER_ID(loggedInUserId), fileWithIncomes(fileNameWithIncomes){

    incomesVector = fileWithIncomes.loadIncomesOfLoggedInUserFromFile(LOGGED_IN_USER_ID);

    };
    int getLastIdIncomes();
    int addIncomes(int loggedInUserId, int lastIdIncomes);
    void showAllIncomes();
    int choiceDateToNewIncomes(char choice);
    bool checkCorrectEnterDate(string date);
    int getDataFromUser(string date);
};

#endif
