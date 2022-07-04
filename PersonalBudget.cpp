#include "PersonalBudget.h"

int PersonalBudget::getLoggedInUserId() {

    return userManager.getLoggedInUserId();
}

void PersonalBudget::loginUser() {

    userManager.loginUser();
}

void PersonalBudget::registerUser() {

    userManager.registerUser();
}

void PersonalBudget::loginExists() {

    userManager.loginExists();
}

void PersonalBudget::changePassword(){

userManager.changePassword(getLoggedInUserId());
}

void PersonalBudget::mainMenu() {

    while (true) {
        if (!userManager.isUserLoggedIn()) {
            choice = userManager.selectOptionFromMainMenu();

            menuLoggedOutUser();

        } else {
            /*
                        if (sprawdzCzyVectorZAdresatamiJestPusty()) {
                            wczytajAdresatowZalogowanegoUzytkownikaZPliku();
                        }
            */
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

        break;
    case '2':

        break;
    case '3':

        break;
    case '4':

        break;
    case '5':

        break;
    case '6':

        break;
    case '7':
        changePassword();
        break;
    case '8':
        loginExists();
        break;

    }
}
