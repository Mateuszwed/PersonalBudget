#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "IncomesManager.h"


using namespace std;

class PersonalBudget {



UserManager userManager;
IncomesManager * incomesManager;

char choice;
const string FILE_NAME_WITH_INCOMES;

void menuLoggedOutUser();
void menuLoggedInUser();
int getLoggedInUserId();
void loginUser();
void registerUser();
void loginExists();
void changePassword();
void addIncomes();

public:

    PersonalBudget(string fileNameWithUsers, string fileNameWithIncomes) : userManager(fileNameWithUsers), FILE_NAME_WITH_INCOMES(fileNameWithIncomes)  {
        incomesManager = NULL;
    };

    ~PersonalBudget(){
    delete incomesManager;
    incomesManager = NULL;
    };

    void mainMenu();
};

#endif
