#include "UserManager.h"


void UserManager::registerUser() {

    User user = getNewUserData();

    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    Sleep(1500);
}


User UserManager::getNewUserData() {

    User user;
    user.setUserId(getNewUserId());
    do {
        cout << "Podaj login: ";
        user.setLogin(AuxiliaryMethods::loadLine());
    } while (checkLogin(user.getLogin()));
    cout << "Podaj haslo: ";
    user.setPassword(AuxiliaryMethods::loadLine());
    cout << "Podaj imie: ";
    user.setName(AuxiliaryMethods::changeFirstLetterForUpperCaseAndOthersForLowerCase(AuxiliaryMethods::loadLine()));
    cout << "Podaj nazwisko: ";
    user.setSurname(AuxiliaryMethods::changeFirstLetterForUpperCaseAndOthersForLowerCase(AuxiliaryMethods::loadLine()));

    return user;
}


int UserManager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}


bool UserManager::checkLogin(string login) {

    for(int i = 0; i < users.size(); i++) {

        if(users[i].getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}


int UserManager::loginUser() {

    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = AuxiliaryMethods::loadLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> User::getLogin() == login) {
            for (int i = 3; i > 0; i--) {
                cout << "Podaj haslo. Pozostalo prob: " << i << ": ";
                password = AuxiliaryMethods::loadLine();

                if (itr -> User::getPassword() == password) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    loggedIdUser = itr -> getUserId();
                    return loggedIdUser;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}


int UserManager::getLoggedInUserId() {

    return loggedIdUser;

}


void UserManager::changePassword(int loggedIdUser) {

    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods::loadLine();

    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUserId() == loggedIdUser) {
            users[i].setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    fileWithUsers.changePassword(loggedIdUser, newPassword);
}

char UserManager::selectOptionFromMainMenu() {


    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";

    choice = AuxiliaryMethods::loadChar();

    return choice;
}



char UserManager::selectOptionFromUserMenu() {

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z zeszlego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadChar();

    return choice;
}


bool UserManager::isUserLoggedIn() {

    if(loggedIdUser > 0) {

        return true;

    } else

        return false;

}


void UserManager::loginExists() {

    loggedIdUser = 0;

}

