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



int IncomesManager::getDateFromUser() {
    string date;
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


int IncomesManager::getLastIdIncomes() {

    return fileWithIncomes.getLastIncomesId();

}


int IncomesManager::choiceDateToNewIncomes(char choice) {

    switch(choice) {
    case 't':
    case 'T':
        return AuxiliaryMethods::getCurrentDateInteger();;
        break;
    case 'n':
    case 'N':
        return getDateFromUser();
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


vector <Incomes> IncomesManager::sortIncomesByDate() {

    sort(incomesVector.begin(), incomesVector.end(),[] (Incomes& beginDate, Incomes& endDate) {
        return beginDate.getDate() < endDate.getDate();
    });

    return incomesVector;
}


float IncomesManager::sumIncomesBalanceCurrentMonth() {

    int currentDate = AuxiliaryMethods::getCurrentDateInteger();
    int currentYearAndMonth = currentDate / 100;
    float sum = 0;
    for(int i = 0; i < incomesVector.size(); i++) {

        if(currentYearAndMonth == incomesVector[i].getDate() / 100) {
            sum += incomesVector[i].getAmount();
        }
    }
    return sum;
}


void IncomesManager::displayIncomesBalanceCurrentMonth() {

    int currentDate = AuxiliaryMethods::getCurrentDateInteger();
    int currentYearAndMonth = currentDate / 100;
    incomesVector = sortIncomesByDate();

    for(int i = 0; i < incomesVector.size(); i++) {

        if(currentYearAndMonth == incomesVector[i].getDate() / 100) {
            cout <<"Przychod: " << incomesVector[i].getItem() <<
                 setw(30 - incomesVector[i].getItem().size()) << " Data: " << AuxiliaryMethods::changeFormatDateToDateWithHyphens(incomesVector[i].getDate()) <<
                 setw(30) << "Kwota: " << incomesVector[i].getAmount() << endl;
        }
    }
}


float IncomesManager::sumIncomesBalanceLastMonth() {

    int lastDate = AuxiliaryMethods::getCurrentDateInteger();
    int lastYearAndMonth = (lastDate / 100) - 1;
    float sum = 0;

    if(lastYearAndMonth & 100 == 0) {

        lastYearAndMonth -= 100;
        lastYearAndMonth += 12;
    }

    for(int i = 0; i < incomesVector.size(); i++) {

        if(lastYearAndMonth == incomesVector[i].getDate() / 100) {
            sum += incomesVector[i].getAmount();
        }
    }
    return sum;
}


void IncomesManager::displayIncomesBalanceLastMonth() {

    int lastDate = AuxiliaryMethods::getCurrentDateInteger();
    int lastYearAndMonth = (lastDate / 100) - 1;
    incomesVector = sortIncomesByDate();

    if(lastYearAndMonth & 100 == 0) {

        lastYearAndMonth -= 100;
        lastYearAndMonth += 12;
    }

    for(int i = 0; i < incomesVector.size(); i++) {

        if(lastYearAndMonth == incomesVector[i].getDate() / 100) {
            cout <<"Przychod: " << incomesVector[i].getItem() <<
                 setw(30 - incomesVector[i].getItem().size()) << " Data: " << AuxiliaryMethods::changeFormatDateToDateWithHyphens(incomesVector[i].getDate()) <<
                 setw(30) << "Kwota: " << incomesVector[i].getAmount() << endl;
        }
    }
}


float IncomesManager::sumIncomesBalanceBetweenTwoDates(int firstDate, int secondDate) {

    float sum = 0;

    for(int i = 0; i < incomesVector.size(); i++) {

        if((incomesVector[i].getDate() >= firstDate) && (incomesVector[i].getDate() <= secondDate)) {
            sum += incomesVector[i].getAmount();
        }
    }
    return sum;
}


void IncomesManager::displayIncomesBalanceBetweenTwoDates(int firstDate, int secondDate) {

    incomesVector = sortIncomesByDate();

    for(int i = 0; i < incomesVector.size(); i++) {

        if((incomesVector[i].getDate() >= firstDate) && (incomesVector[i].getDate() <= secondDate)) {
            cout <<"Przychod: " << incomesVector[i].getItem() <<
                 setw(30 - incomesVector[i].getItem().size()) << " Data: " << AuxiliaryMethods::changeFormatDateToDateWithHyphens(incomesVector[i].getDate()) <<
                 setw(30) << "Kwota: " << incomesVector[i].getAmount() << endl;
        }
    }
}
