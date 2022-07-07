#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager {

    char choice;
    int loggedIdUser;
    vector <User> users;

    FileWithUsers fileWithUsers;
    User getNewUserData();
    int getNewUserId();


public:
    UserManager(string fileNameWithUsers) : fileWithUsers(fileNameWithUsers) {
        loggedIdUser = 0;
        users = fileWithUsers.loadUsersFromFile();
    }

    char selectOptionFromUserMenu() ;
    char selectOptionFromMainMenu();
    bool checkLogin(string login);
    void registerUser();
    int loginUser();
    void changePassword(int loggedIdUser);
    int getLoggedInUserId();
    void loginExists();
    bool isUserLoggedIn();
};

#endif
