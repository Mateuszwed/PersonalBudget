#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"


using namespace std;

class PersonalBudget {

char choice;

UserManager userManager;


void menuLoggedOutUser();
void menuLoggedInUser();
int getLoggedInUserId();
void loginUser();
void registerUser();
void loginExists();
void changePassword();

public:

    PersonalBudget(string fileNameWithUsers) : userManager(fileNameWithUsers) {
    };

    ~PersonalBudget(){}

    void mainMenu();
};

#endif
