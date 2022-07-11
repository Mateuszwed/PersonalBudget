#include "FileWithExpenses.h"


int FileWithExpenses::getLastExpensesId() {

    CMarkup xml;

    int lastId = 0;

    bool fileExists = xml.Load( FILE_NAME_WITH_EXPENSES );
    if(fileExists) {
        xml.FindElem("Expenses");
        xml.IntoElem();
        while(xml.FindElem("expense")) {
            xml.IntoElem();
            xml.FindElem("id");
            lastId = AuxiliaryMethods::convertStringToInt(xml.GetData());
            xml.OutOfElem();
        }
    } else {
        lastId = 0;
    }
    return lastId;
}


void FileWithExpenses::addExpensesToFile(Expenses expenses) {

    CMarkup xml;

    bool fileExists = xml.Load( FILE_NAME_WITH_EXPENSES );

    if(!fileExists) {

        xml.AddElem( "Expenses" );

    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "expense" );
    xml.IntoElem();
    xml.AddElem( "id", expenses.getId() );
    xml.AddElem( "userId", expenses.getUserId() );
    xml.AddElem( "item", expenses.getItem() );
    xml.AddElem( "date", BalanceManager::changeFormatDateToDateWithHyphens(expenses.getDate()) );
    xml.AddElem( "amount", AuxiliaryMethods::convertFloatToString(expenses.getAmount() ));

    xml.Save(FILE_NAME_WITH_EXPENSES);


}


vector <Expenses> FileWithExpenses::loadExpensesOfLoggedInUserFromFile(int loggedInUserId) {

    CMarkup xml;

    vector <Expenses> expensesVector;
    Expenses expenses;
    int userId = 0;
    int id = 0;

    bool fileExists = xml.Load( FILE_NAME_WITH_EXPENSES );

    if(fileExists) {
        xml.FindElem("Expenses");
        xml.IntoElem();
        while(xml.FindElem("expense")) {
            xml.IntoElem();
            xml.FindElem("id");
            id = AuxiliaryMethods::convertStringToInt(xml.GetData());
            xml.FindElem("userId");
            userId = AuxiliaryMethods::convertStringToInt(xml.GetData());
            if(userId == loggedInUserId) {
                expenses.setId(id);
                expenses.setUserId(userId);
                xml.FindElem("item");
                expenses.setItem(xml.GetData());
                xml.FindElem("date");
                expenses.setDate(BalanceManager::changeFormatDateToInt(xml.GetData()));
                xml.FindElem("amount");
                expenses.setAmount(AuxiliaryMethods::convertStringToFloat(xml.GetData()));
                xml.OutOfElem();
                expensesVector.push_back(expenses);

            } else {
                xml.OutOfElem();
            }
        }

    }
    return expensesVector;
}

