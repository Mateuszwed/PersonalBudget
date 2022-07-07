#include "PersonalBudget.h"

int PersonalBudget::getLoggedInUserId() {

    return userManager.getLoggedInUserId();
}

void PersonalBudget::loginUser() {

    userManager.loginUser();
    if(userManager.isUserLoggedIn()){

            incomesManager = new IncomesManager(FILE_NAME_WITH_INCOMES, getLoggedInUserId());
            expensesManager = new ExpensesManager(FILE_NAME_WITH_EXPENSES, getLoggedInUserId());

       }
}

void PersonalBudget::registerUser() {

    userManager.registerUser();
}

void PersonalBudget::loginExists() {

    userManager.loginExists();
}

void PersonalBudget::changePassword() {

    userManager.changePassword(getLoggedInUserId());
}


void PersonalBudget::addIncomes(){

    incomesManager->addIncomes(getLoggedInUserId(), incomesManager->getLastIdIncomes());

}

void PersonalBudget::addExpenses(){

expensesManager->addExpenses(getLoggedInUserId(), expensesManager->getLastIdExpenses());

}



void PersonalBudget::mainMenu() {

    while (true) {
        if (!userManager.isUserLoggedIn()) {
            choice = userManager.selectOptionFromMainMenu();

            menuLoggedOutUser();

        } else {

            choice = userManager.selectOptionFromUserMenu();
            menuLoggedInUser();

        }
    }
}

void PersonalBudget::menuLoggedOutUser() {

    switch (choice) {
    case '1':
        registerUser();
        break;
    case '2':
        loginUser();
        break;
    case '9':
        exit(0);
        break;
    default:
        cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
        system("pause");
        break;
    }

}

void PersonalBudget::menuLoggedInUser() {

    switch (choice) {
    case '1':
        addIncomes();
        break;
    case '2':
        addExpenses();
        break;
    case '3':
        expensesManager->displayExpensesBilansCurrentMonth();
        incomesManager->displayIncomesBilansCurrentMonth();
        system("pause");
        break;
    case '4':

        break;
    case '5':
        break;
    case '6':
        incomesManager->showAllIncomes();
        break;
    case '7':
        changePassword();
        break;
    case '8':
        loginExists();
        break;

    }
}
