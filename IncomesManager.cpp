#include "IncomesManager.h"


Incomes IncomesManager::getDataNewIncomes(int loggedInUserId, int lastIdIncomes) {

    Incomes incomes;
    int date = 0;
    float amount = 0;
    string item = "";
    incomes.setIncomesId(++lastIdIncomes);
    incomes.setUserId(loggedInUserId);

    cout << "Czy chcesz dodac przychod z dzisiejsza data <t/n>?:  " << AuxiliaryMethods::getCurrentDate() << endl;
    date = choiceDateToNewIncomes(AuxiliaryMethods::loadChar());
    incomes.setDate(date);


    item = getItemFromUser();
    incomes.setItem(item);

    amount = getAmountFromUser();
    incomes.setAmount(amount);

    cout << endl << "Przychod zostal zapisany w bazie danych." << endl;
    Sleep(1500);
    return incomes;
}


void IncomesManager::convertDateToArray(int dateArray[], string date) {

    dateArray[0] = AuxiliaryMethods::convertStringToInt(date.substr(0,4));
    dateArray[1] = AuxiliaryMethods::convertStringToInt(date.substr(5,2));
    dateArray[2] = AuxiliaryMethods::convertStringToInt(date.substr(8,2));

}


bool IncomesManager::compareTwoDates(int dateTab[], int currentDateTab[]) {

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


bool IncomesManager::checkCorrectEnterDate(string date) {

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


bool IncomesManager::checkCorrectEnterAmount(string amount) {
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


string  IncomesManager::getItemFromUser() {
    string item = "";
    bool ifCorrect = true;
    while(ifCorrect) {
        cout << "Podaj czego dotyczy przychod: ";
        item = AuxiliaryMethods::loadLine();
        if(item.length() >= 1) {
            return item;
        } else {
            cout << "Pole forumlarza nie moze byc puste." << endl;
            ifCorrect = true;
        }

    }
}


float IncomesManager::getAmountFromUser() {
    string amount = "";
    bool ifCorrect = true;
    while(ifCorrect) {
        cout << "Podaj wysokosc przchodu: ";
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



int IncomesManager::getDataFromUser(string date) {
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



int IncomesManager::getLastIdIncomes() {

    return fileWithIncomes.getLastIncomesId();

}


int IncomesManager::choiceDateToNewIncomes(char choice) {

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


int IncomesManager::addIncomes(int loggedInUserId, int lastIdIncomes) {

    Incomes incomes;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    incomes = getDataNewIncomes(loggedInUserId, lastIdIncomes);
    incomesVector.push_back(incomes);
    fileWithIncomes.addIncomesToFile(incomes);

    return ++lastIdIncomes;
}


void IncomesManager::showAllIncomes() {

    for(int i = 0; i < incomesVector.size(); i++) {

        cout << "User id: " << incomesVector[i].getUserId() <<
             " Incomes id: " << incomesVector[i].getIncomesId() <<
             " Item: " << incomesVector[i].getItem() <<
             " Date: " << incomesVector[i].getDate() <<
             " Amount: " << incomesVector[i].getAmount() << endl;

    }
    system("pause");
}
