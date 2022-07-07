#include "ExpensesManager.h"


Expenses ExpensesManager::getDataNewExpenses(int loggedInUserId, int lastIdExpenses) {

    Expenses expenses;
    int date = 0;
    float amount = 0;
    string item = "";
    expenses.setExpensesId(++lastIdExpenses);
    expenses.setUserId(loggedInUserId);

    cout << "Czy chcesz dodac wydatek z dzisiejsza data <t/n>?:  " << AuxiliaryMethods::getCurrentDate() << endl;
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


void ExpensesManager::convertDateToArray(int dateArray[], string date) {

    dateArray[0] = AuxiliaryMethods::convertStringToInt(date.substr(0,4));
    dateArray[1] = AuxiliaryMethods::convertStringToInt(date.substr(5,2));
    dateArray[2] = AuxiliaryMethods::convertStringToInt(date.substr(8,2));

}


bool ExpensesManager::compareTwoDates(int dateTab[], int currentDateTab[]) {

    if(dateTab[0] < 2000) {
        return false;
    } else if (dateTab[0] > currentDateTab[0]) {
        return false;
    } else if (dateTab[0] == currentDateTab[0]) {
        if (dateTab[1] > currentDateTab[1]) {
            return false;
        }
    }
    return true;
}


bool ExpensesManager::checkCorrectEnterDate(string date) {

    int dateArray[3];
    int currentDateArray[3];
    string currentDate = AuxiliaryMethods::getCurrentDate();

    if((date.length() < 10) || (date.length() > 10)) {
        return false;
    }

    convertDateToArray(dateArray, date);
    convertDateToArray(currentDateArray, currentDate);

    if(!compareTwoDates(dateArray, currentDateArray)) {
        return false;
    }

    switch(dateArray[1]) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if((dateArray[2] < 1) || (dateArray[2] > 31)) {
            return false;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if((dateArray[2] < 1) || (dateArray[2] > 30)) {
            return false;
        }
        break;
    case 2:
        if(!AuxiliaryMethods::checkIsYearIsLeapYear(dateArray[0])) {

            if((dateArray[2] < 1) || (dateArray[2] > 28)) {
                return false;
            }
        }
        break;
    default:
        return false;
    }

    return true;

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
        amount = AuxiliaryMethods::replaceCommaToDot(amount);
        if(checkCorrectEnterAmount(amount)) {
            return AuxiliaryMethods::convertStringToFloat(amount);
        } else {
            cout << "Podales zly format wysokosci przychodu." << endl;
            ifCorrect = true;
        }

    }
}



int ExpensesManager::getDataFromUser(string date) {
    bool ifCorrect = true;
    while(ifCorrect) {
        cout << "Podaj date przychodu: ";
        date = AuxiliaryMethods::loadLine();
        if(checkCorrectEnterDate(date)) {
            return AuxiliaryMethods::changeFormatDateToInt(date);
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

    string date;

    switch(choice) {
    case 't':
    case 'T':
        return AuxiliaryMethods::changeFormatDateToInt(AuxiliaryMethods::getCurrentDate());
        break;
    case 'n':
    case 'N':
        return getDataFromUser(date);
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

    sort(expensesVector.begin(), expensesVector.end(),[] (Expenses& beginDate, Expenses& endDate) {
        return beginDate.getDate() < endDate.getDate();
    });

    return expensesVector;
}

void ExpensesManager::displayExpensesBilansCurrentMonth() {

    int currentDate = AuxiliaryMethods::changeFormatDateToInt(AuxiliaryMethods::getCurrentDate());
    int currentMonth = AuxiliaryMethods::getMonth(currentDate);
    expensesVector = sortExpensesByDate();

    for(int i = 0; i < expensesVector.size(); i++) {

        if(currentMonth == AuxiliaryMethods::getMonth(expensesVector[i].getDate())) {
            cout << "User id: " << expensesVector[i].getUserId() <<
                 " Expendes id: " << expensesVector[i].getExpensesId() <<
                 " Item: " << expensesVector[i].getItem() <<
                 " Date: " << AuxiliaryMethods::changeFormatDateToDateWithHyphens(expensesVector[i].getDate()) <<
                 " Amount: " << expensesVector[i].getAmount() << endl;
        }
    }

}



void ExpensesManager::showAllExpenses() {

    for(int i = 0; i < expensesVector.size(); i++) {

        cout << "User id: " << expensesVector[i].getUserId() <<
             " Expenses id: " << expensesVector[i].getExpensesId() <<
             " Item: " << expensesVector[i].getItem() <<
             " Date: " << expensesVector[i].getDate() <<
             " Amount: " << expensesVector[i].getAmount() << endl;

    }
    system("pause");
}
