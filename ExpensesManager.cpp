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


bool ExpensesManager::checkDateIsNotHigherThanCurrentDate(int date) {

    int dateYear = AuxiliaryMethods::getYear(date);
    int dateMonth = AuxiliaryMethods::getMonth(date);
    int currentDate = AuxiliaryMethods::getCurrentDateInteger();
    int currentDateYear = AuxiliaryMethods::getYear(currentDate);
    int currentDateMonth = AuxiliaryMethods::getMonth(currentDate);

    if(dateYear < 2000) {
        return false;
    } else if (dateYear > currentDateYear) {
        return false;
    } else if (dateYear == currentDateYear) {
        if (dateMonth > currentDateMonth) {
            return false;
        }
    }
    return true;
}

bool ExpensesManager::checkCorrectEnterDate(string date) {

    if((date.length() < 10) || (date.length() > 10)) {
        return false;
    }
    int dateInt = AuxiliaryMethods::changeFormatDateToInt(date);
    int dateMonth = AuxiliaryMethods::getMonth(dateInt);
    int dateYear = AuxiliaryMethods::getYear(dateInt);


    switch(dateMonth) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if((dateMonth < 1) || (dateMonth > 31)) {
            return false;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if((dateMonth < 1) || (dateMonth > 30)) {
            return false;
        }
        break;
    case 2:
        if(!AuxiliaryMethods::checkIsYearIsLeapYear(dateYear)) {

            if((dateMonth < 1) || (dateMonth > 28)) {
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
        if((checkCorrectEnterDate(date)) && (checkDateIsNotHigherThanCurrentDate(AuxiliaryMethods::changeFormatDateToInt(date)))) {
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

    switch(choice) {
    case 't':
    case 'T':
        return AuxiliaryMethods::changeFormatDateToInt(AuxiliaryMethods::getCurrentDate());
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

    sort(expensesVector.begin(), expensesVector.end(),[] (Expenses& beginDate, Expenses& endDate) {
        return beginDate.getDate() < endDate.getDate();
    });

    return expensesVector;
}

float ExpensesManager::sumExpensesBalanceCurrentMonth() {

    int currentDate = AuxiliaryMethods::getCurrentDateInteger();
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

    int currentDate = AuxiliaryMethods::getCurrentDateInteger();
    int currentYearAndMonth = currentDate / 100;
    expensesVector = sortExpensesByDate();

    for(int i = 0; i < expensesVector.size(); i++) {

        if(currentYearAndMonth == expensesVector[i].getDate() / 100) {
            cout <<"Wydatek: " << expensesVector[i].getItem() <<
                 setw(31 - expensesVector[i].getItem().size()) << " Data: " << AuxiliaryMethods::changeFormatDateToDateWithHyphens(expensesVector[i].getDate()) <<
                 setw(30) << "Kwota: " << expensesVector[i].getAmount() << endl;
        }
    }
}


float ExpensesManager::sumExpensesBalanceLastMonth() {

    int lastDate = AuxiliaryMethods::getCurrentDateInteger();
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

    int lastDate = AuxiliaryMethods::getCurrentDateInteger();
    int lastYearAndMonth = (lastDate / 100) - 1;
    expensesVector = sortExpensesByDate();

    if(lastYearAndMonth & 100 == 0) {

        lastYearAndMonth -= 100;
        lastYearAndMonth += 12;
    }

    for(int i = 0; i < expensesVector.size(); i++) {

        if(lastYearAndMonth == expensesVector[i].getDate() / 100) {
            cout <<"Wydatek: " << expensesVector[i].getItem() <<
                 setw(31 - expensesVector[i].getItem().size()) << " Data: " << AuxiliaryMethods::changeFormatDateToDateWithHyphens(expensesVector[i].getDate()) <<
                 setw(30) << "Kwota: " << expensesVector[i].getAmount() << endl;
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
            cout <<"Wydatek: " << expensesVector[i].getItem() <<
                 setw(31 - expensesVector[i].getItem().size()) << " Data: " << AuxiliaryMethods::changeFormatDateToDateWithHyphens(expensesVector[i].getDate()) <<
                 setw(30) << "Kwota: " << expensesVector[i].getAmount() << endl;
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
