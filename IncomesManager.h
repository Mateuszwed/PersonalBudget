#ifndef INCOMESMANAGER_H
#define INCOMESMANAGER_H

#include <iostream>
#include <vector>
#include <iomanip>

#include "BalanceManager.h"
#include "Incomes.h"
#include "FileWithIncomes.h"



using namespace std;

class IncomesManager : public BalanceManager{

    const int LOGGED_IN_USER_ID;
    vector <Incomes> incomesVector;
    FileWithIncomes fileWithIncomes;
    Incomes getDataNewIncomes(int loggedInUserId, int lastIdIncomes);
    bool checkCorrectEnterAmount(string amount);
    float getAmountFromUser();
    vector <Incomes> sortIncomesByDate();
    string getItemFromUser();

public:

    IncomesManager(string fileNameWithIncomes, int loggedInUserId) : LOGGED_IN_USER_ID(loggedInUserId), fileWithIncomes(fileNameWithIncomes){

    incomesVector = fileWithIncomes.loadIncomesOfLoggedInUserFromFile(LOGGED_IN_USER_ID);

    };
    int getLastIdIncomes();
    int addIncomes(int loggedInUserId, int lastIdIncomes);
    int choiceDateToNewIncomes(char choice);
    int getDateFromUser();
    void displayIncomesBalanceCurrentMonth();
    float sumIncomesBalanceCurrentMonth();
    void displayIncomesBalanceLastMonth();
    float sumIncomesBalanceLastMonth();
    void displayIncomesBalanceBetweenTwoDates(int firstDate, int secondDate);
    float sumIncomesBalanceBetweenTwoDates(int firstDate, int secondDate);
    int getFirstDateFromUser();
    int getSecondDateFromUser();
};

#endif
