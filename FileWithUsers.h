#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>


#include "Markup.h"
#include "User.h"
#include "AuxiliaryMethods.h"


using namespace std;

class FileWithUsers {

const string FILE_NAME;


public:

    FileWithUsers(string fileName) : FILE_NAME(fileName){}
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void saveAllUsersToFile( vector<User> users);
    void changePassword(int loggedIdUser, string newPassword);

};

#endif
