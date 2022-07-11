#include "FileWithUsers.h"



void FileWithUsers::addUserToFile(User user) {


    bool fileExists = xml.Load( FILE_NAME );

    if(!fileExists) {

        xml.AddElem( "Users" );

    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "user" );
    xml.IntoElem();
    xml.AddElem( "id", user.getUserId() );
    xml.AddElem( "login", user.getLogin() );
    xml.AddElem( "password", user.getPassword() );
    xml.AddElem( "name", user.getName() );
    xml.AddElem( "surname", user.getSurname() );

    xml.Save("Users.xml");

}


vector <User> FileWithUsers::loadUsersFromFile() {

    User user;
    vector <User> users;
    xml.Load( FILE_NAME );
    xml.FindElem("Users");
    xml.IntoElem();
    while(xml.FindElem("user")) {

        xml.IntoElem();
        xml.FindElem("id");
        user.setUserId(AuxiliaryMethods::convertStringToInt(xml.GetData()));
        xml.FindElem("login");
        user.setLogin(xml.GetData());
        xml.FindElem("password");
        user.setPassword(xml.GetData());
        xml.FindElem("name");
        user.setName(xml.GetData());
        xml.FindElem("surname");
        user.setSurname(xml.GetData());
        xml.OutOfElem();

        users.push_back(user);
    }

    return users;
}


void FileWithUsers::changePassword(int loggedIdUser, string newPassword) {

    string id;

    xml.Load(FILE_NAME);
    xml.FindElem("Users");
    xml.IntoElem();
    while(xml.FindElem("user")) {
        xml.IntoElem();
        xml.FindElem("id");
        id = xml.GetData();
        if(AuxiliaryMethods::convertStringToInt(id) == loggedIdUser) {
            xml.FindElem("password");
            xml.RemoveElem();
            xml.AddElem("password", newPassword);
            break;
        }
        xml.OutOfElem();
    }
    xml.Save(FILE_NAME);

}
