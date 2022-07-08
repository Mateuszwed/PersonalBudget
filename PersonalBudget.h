#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "IncomesManager.h"
#include "ExpensesManager.h"


using namespace std;

class PersonalBudget {



UserManager userManager;
IncomesManager *incomesManager;
ExpensesManager *expensesManager;

char choice;
const string FILE_NAME_WITH_INCOMES;
const string FILE_NAME_WITH_EXPENSES;

void menuLoggedOutUser();
void menuLoggedInUser();
int getLoggedInUserId();
void loginUser();
void registerUser();
void loginExists();
void changePassword();
void addIncomes();
void addExpenses();
void displaySumBalance(float sumOfExpenses, float sumOfIncomes);
void displayBalanceCurrentMonth();
void displayBalanceLastMonth();
float sumExpensesBalanceCurrentMonth();
float sumIncomesBalanceCurrentMonth();
float sumExpensesBalanceLastMonth();
float sumIncomesBalanceLastMonth();
void displayBalanceSheetForSelectedPeriod();
int getFirstDateFromUserToBalanceBetweenDates();
int getSecondDateFromUserToBalanceBetweenDates();

public:

    PersonalBudget(string fileNameWithUsers, string fileNameWithIncomes, string fileNameWithExpenses) : userManager(fileNameWithUsers),
    FILE_NAME_WITH_INCOMES(fileNameWithIncomes), FILE_NAME_WITH_EXPENSES(fileNameWithExpenses)  {

        incomesManager = NULL;
        expensesManager = NULL;
    };

    ~PersonalBudget(){
    delete incomesManager;
    delete expensesManager;
    expensesManager = NULL;
    incomesManager = NULL;
    };

    void mainMenu();
};

#endif
