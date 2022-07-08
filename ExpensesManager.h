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
    string getItemFromUser();
    vector <Expenses> sortExpensesByDate();
    bool checkDateIsNotHigherThanCurrentDate(int date);
public:

    ExpensesManager(string fileNameWithExpenses, int loggedInUserId) : LOGGED_IN_USER_ID(loggedInUserId), fileWithExpenses(fileNameWithExpenses){

    expensesVector = fileWithExpenses.loadExpensesOfLoggedInUserFromFile(LOGGED_IN_USER_ID);

    };
    int getLastIdExpenses();
    int addExpenses(int loggedInUserId, int lastIdExpenses);
    void showAllExpenses();
    int choiceDateToNewExpenses(char choice);
    bool checkCorrectEnterDate(string date);
    int getDataFromUser();
    void displayExpensesBalanceCurrentMonth();
    float sumExpensesBalanceCurrentMonth();
    void displayExpensesBalanceLastMonth();
    float sumExpensesBalanceLastMonth();
    float sumExpensesBalanceBetweenTwoDates(int firstDate, int secondDate);
    void displayExpensesBalanceBetweenTwoDates(int firstDate, int secondDate);
};

#endif
