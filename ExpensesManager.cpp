#include "ExpensesManager.h"


Expenses ExpensesManager::getDataNewExpenses(int loggedInUserId, int lastIdExpenses) {

    Expenses expenses;
    int date = 0;
    float amount = 0;
    string item = "";
    expenses.setId(++lastIdExpenses);
    expenses.setUserId(loggedInUserId);

    cout << "Czy chcesz dodac wydatek z dzisiejsza data <t/n>?:  " << getCurrentDate() << endl;
    date = choiceDateToNewExpenses(AuxiliaryMethods::loadChar());
    expenses.setDate(date);


    item = getItemFromUser();
    expenses.setItem(item);

    amount = getAmountFromUser();
    expenses.setAmount(amount);

    cout << endl << "Wydatek zostal zapisany w bazie danych." << endl;
    Sleep(1500);
    return expenses;
}


bool ExpensesManager::checkCorrectEnterAmount(string amount) {
    for(int i = 0; i < amount.length(); i++) {
        if(amount[i] == '.') {
            continue;
        } else if (!isdigit(amount[i])) {
            return false;
            break;
        } else if(amount.empty()) {
            return false;
            break;
        }
    }
    return true;
}


string  ExpensesManager::getItemFromUser() {
    string item = "";
    bool ifCorrect = true;
    while(ifCorrect) {
        cout << "Podaj czego dotyczy wydatek: ";
        item = AuxiliaryMethods::loadLine();
        if(item.length() >= 1) {
            return item;
        } else {
            cout << "Pole forumlarza nie moze byc puste." << endl;
            ifCorrect = true;
        }

    }
}


float ExpensesManager::getAmountFromUser() {
    string amount = "";
    bool ifCorrect = true;
    while(ifCorrect) {
        cout << "Podaj wysokosc wydatku: ";
        amount = AuxiliaryMethods::loadLine();
        amount = replaceCommaToDot(amount);
        if(checkCorrectEnterAmount(amount)) {
            return AuxiliaryMethods::convertStringToFloat(amount);
        } else {
            cout << "Podales zly format wysokosci wydatku." << endl;
            ifCorrect = true;
        }

    }
}



int ExpensesManager::getDataFromUser() {
    string date = "";
    bool ifCorrect = true;
    while(ifCorrect) {
        cout << "Podaj date przychodu: ";
        date = AuxiliaryMethods::loadLine();
        if((checkCorrectEnterDate(date)) && (checkDateIsNotHigherThanCurrentDate(changeFormatDateToInt(date)))) {
            return changeFormatDateToInt(date);
        } else {
            cout << "Podales zly format daty." << endl;
            ifCorrect = true;
        }
    }
}



int ExpensesManager::getLastIdExpenses() {

    return fileWithExpenses.getLastExpensesId();

}


int ExpensesManager::choiceDateToNewExpenses(char choice) {

    switch(choice) {
    case 't':
    case 'T':
        return getCurrentDateInteger();
        break;
    case 'n':
    case 'N':
        return getDataFromUser();
        break;
    default:
        cout << "Nieprawidlowy znak, wybierz <t/n> " << endl;
        break;

    }

}


int ExpensesManager::addExpenses(int loggedInUserId, int lastIdExpenses) {

    Expenses expenses;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    expenses = getDataNewExpenses(loggedInUserId, lastIdExpenses);
    expensesVector.push_back(expenses);
    fileWithExpenses.addExpensesToFile(expenses);

    return ++lastIdExpenses;
}


vector <Expenses> ExpensesManager::sortExpensesByDate() {

    sort(expensesVector.begin(), expensesVector.end(),[] (Expenses& firstExpense, Expenses& secondExpense) {
        return firstExpense.getDate() < secondExpense.getDate();
    });

    return expensesVector;
}

float ExpensesManager::sumExpensesBalanceCurrentMonth() {

    int currentDate = getCurrentDateInteger();
    int currentYearAndMonth = currentDate / 100;
    float sum = 0;

    for(int i = 0; i < expensesVector.size(); i++) {

        if(currentYearAndMonth == expensesVector[i].getDate() / 100) {
        sum += expensesVector[i].getAmount();
        }
    }
    return sum;
}


void ExpensesManager::displayExpensesBalanceCurrentMonth() {

    int currentDate = getCurrentDateInteger();
    int currentYearAndMonth = currentDate / 100;
    expensesVector = sortExpensesByDate();

    for(int i = 0; i < expensesVector.size(); i++) {

        if(currentYearAndMonth == expensesVector[i].getDate() / 100) {

            cout << "Wydatek: " << expensesVector[i].getItem() <<
                 setw(31 - expensesVector[i].getItem().size()) << " Data: " << changeFormatDateToDateWithHyphens(expensesVector[i].getDate()) <<
                 setw(30) << "Kwota: " << fixed << setprecision(2) << expensesVector[i].getAmount() << endl;
        }
    }
}


float ExpensesManager::sumExpensesBalanceLastMonth() {

    int lastDate = getCurrentDateInteger();
    int lastYearAndMonth = (lastDate / 100) - 1;
    float sum = 0;

    if(lastYearAndMonth & 100 == 0) {

        lastYearAndMonth -= 100;
        lastYearAndMonth += 12;
    }

    for(int i = 0; i < expensesVector.size(); i++) {

        if(lastYearAndMonth == expensesVector[i].getDate() / 100) {
            sum += expensesVector[i].getAmount();
        }
    }
    return sum;
}


void ExpensesManager::displayExpensesBalanceLastMonth() {

    int lastDate = getCurrentDateInteger();
    int lastYearAndMonth = (lastDate / 100) - 1;
    expensesVector = sortExpensesByDate();

    if(lastYearAndMonth & 100 == 0) {

        lastYearAndMonth -= 100;
        lastYearAndMonth += 12;
    }

    for(int i = 0; i < expensesVector.size(); i++) {

        if(lastYearAndMonth == expensesVector[i].getDate() / 100) {

            cout << "Wydatek: " << expensesVector[i].getItem() <<
                 setw(31 - expensesVector[i].getItem().size()) << " Data: " << changeFormatDateToDateWithHyphens(expensesVector[i].getDate()) <<
                 setw(30) << "Kwota: " << fixed << setprecision(2) << expensesVector[i].getAmount() << endl;
        }
    }
}


float ExpensesManager::sumExpensesBalanceBetweenTwoDates(int firstDate, int secondDate) {

    float sum = 0;

    for(int i = 0; i < expensesVector.size(); i++) {

        if((expensesVector[i].getDate() >= firstDate) && (expensesVector[i].getDate() <= secondDate)) {
            sum += expensesVector[i].getAmount();
        }
    }
    return sum;
}


void ExpensesManager::displayExpensesBalanceBetweenTwoDates(int firstDate, int secondDate) {

    expensesVector = sortExpensesByDate();

    for(int i = 0; i < expensesVector.size(); i++) {

        if((expensesVector[i].getDate() >= firstDate) && (expensesVector[i].getDate() <= secondDate)) {

            cout << "Wydatek: " << expensesVector[i].getItem() <<
                 setw(31 - expensesVector[i].getItem().size()) << " Data: " << changeFormatDateToDateWithHyphens(expensesVector[i].getDate()) <<
                 setw(30) << "Kwota: " << fixed << setprecision(2) << expensesVector[i].getAmount() << endl;
        }
    }
}


