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

float PersonalBudget::sumExpensesBalanceCurrentMonth(){

return expensesManager->sumExpensesBalanceCurrentMonth();
}

float PersonalBudget::sumIncomesBalanceCurrentMonth(){

return incomesManager->sumIncomesBalanceCurrentMonth();
}

float PersonalBudget::sumExpensesBalanceLastMonth(){

return expensesManager->sumExpensesBalanceLastMonth();
}

float PersonalBudget::sumIncomesBalanceLastMonth(){

return incomesManager->sumIncomesBalanceLastMonth();
}

int PersonalBudget::getFirstDateFromUserToBalanceBetweenDates(){

return balanceManager->getFirstDateFromUser();

}

int PersonalBudget::getSecondDateFromUserToBalanceBetweenDates(){

return balanceManager->getSecondDateFromUser();

}

void PersonalBudget::displaySumBalance(float sumOfExpenses, float sumOfIncomes){

float different = sumOfIncomes - sumOfExpenses;
cout << endl << "-------------------------------------------------------------------------------------------------------------" << endl;
cout << "Suma wydatkow: " << fixed << setprecision(2) << sumOfExpenses << "      Suma przychodow: " << fixed << setprecision(2) << sumOfIncomes << "     Roznica: " << fixed << setprecision(2) << different << endl << endl;

}

void PersonalBudget::displayBalanceCurrentMonth(){

expensesManager->displayExpensesBalanceCurrentMonth();
incomesManager->displayIncomesBalanceCurrentMonth();
displaySumBalance(sumExpensesBalanceCurrentMonth(), sumIncomesBalanceCurrentMonth());
system("pause");

}

void PersonalBudget::displayBalanceLastMonth(){

expensesManager->displayExpensesBalanceLastMonth();
incomesManager->displayIncomesBalanceLastMonth();
displaySumBalance(sumExpensesBalanceLastMonth(), sumIncomesBalanceLastMonth());
system("pause");

}

void PersonalBudget::displayBalanceSheetForSelectedPeriod() {
    int firstDate = 0;
    int secondDate = 0;
    do {

        firstDate = getFirstDateFromUserToBalanceBetweenDates();
        secondDate = getSecondDateFromUserToBalanceBetweenDates();
        if(firstDate > secondDate) {
            cout << "Wpisany zakres dat jest nieprawidlowy." << endl;
        }
    } while(firstDate > secondDate);
    cout << endl;
    expensesManager->displayExpensesBalanceBetweenTwoDates(firstDate, secondDate);
    incomesManager->displayIncomesBalanceBetweenTwoDates(firstDate, secondDate);

    displaySumBalance(expensesManager->sumExpensesBalanceBetweenTwoDates(firstDate, secondDate), incomesManager->sumIncomesBalanceBetweenTwoDates(firstDate, secondDate));
    system("pause");
}



char PersonalBudget::selectOptionFromMainMenu(){

return userManager.selectOptionFromMainMenu();
}


char PersonalBudget::selectOptionFromUserMenu(){

return userManager.selectOptionFromUserMenu();
}



void PersonalBudget::mainMenu() {

    while (true) {
        if (!userManager.isUserLoggedIn()) {
            choice = selectOptionFromMainMenu();

            menuLoggedOutUser();

        } else {

            choice = selectOptionFromUserMenu();
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
        displayBalanceCurrentMonth();
        break;
    case '4':
        displayBalanceLastMonth();
        break;
    case '5':
        displayBalanceSheetForSelectedPeriod();
        break;
    case '6':
        changePassword();
        break;
    case '7':
        loginExists();
        break;

    }
}
