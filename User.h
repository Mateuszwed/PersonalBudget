#ifndef USER_H
#define USER_H

#include <iostream>


using namespace std;

class User {

    int userId;
    string login;
    string password;
    string name;
    string surname;

public:
    void setUserId(int newUserId);
    void setLogin(string newLogin);
    void setPassword(string newPassword);
    void setName(string newName);
    void setSurname(string newSurname);


    int getUserId();
    string getLogin();
    string getPassword();
    string getName();
    string getSurname();
};

#endif
