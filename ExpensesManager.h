#ifndef EXPENSESMANAGER_H
#define EXPENSESMANAGER_H

#include <iostream>
#include <vector>

#include "Expenses.h"
#include "FileWithExpenses.h"


using namespace std;

class ExpensesManager {

    const int LOGGED_IN_USER_ID;
    vector <Expenses> expensesVector;
    FileWithExpenses fileWithExpenses;
    Expenses getDataNewExpenses(int loggedInUserId, int lastIdExpenses);
    bool checkCorrectEnterAmount(string amount);
    float getAmountFromUser();
    bool compareTwoDates(int dateTab[], int currentDateTab[]);
    void convertDateToArray(int dateArray[], string date);
    string getItemFromUser();
    vector <Expenses> sortExpensesByDate();
public:

    ExpensesManager(string fileNameWithExpenses, int loggedInUserId) : LOGGED_IN_USER_ID(loggedInUserId), fileWithExpenses(fileNameWithExpenses){

    expensesVector = fileWithExpenses.loadExpensesOfLoggedInUserFromFile(LOGGED_IN_USER_ID);

    };
    int getLastIdExpenses();
    int addExpenses(int loggedInUserId, int lastIdExpenses);
    void showAllExpenses();
    int choiceDateToNewExpenses(char choice);
    bool checkCorrectEnterDate(string date);
    int getDataFromUser(string date);
    void displayExpensesBilansCurrentMonth();
};

#endif
