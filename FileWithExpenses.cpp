#include "FileWithExpenses.h"


int FileWithExpenses::getLastExpensesId() {

    int lastId = 0;

    bool fileExists = xml.Load( FILE_NAME_WITH_EXPENSES );
    if(fileExists) {
        xml.FindElem("Expenses");
        xml.IntoElem();
        while(xml.FindElem("expenses")) {
            xml.IntoElem();
            xml.FindElem("expensesId");
            lastId = AuxiliaryMethods::convertStringToInt(xml.GetData());
            xml.OutOfElem();
        }
    } else {
        lastId = 0;
    }
    return lastId;
}


void FileWithExpenses::addExpensesToFile(Expenses expenses) {

    bool fileExists = xml.Load( FILE_NAME_WITH_EXPENSES );

    if(!fileExists) {

        xml.AddElem( "Expenses" );

    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "expenses" );
    xml.IntoElem();
    xml.AddElem( "expensesId", expenses.getExpensesId() );
    xml.AddElem( "userId", expenses.getUserId() );
    xml.AddElem( "item", expenses.getItem() );
    xml.AddElem( "date", AuxiliaryMethods::changeFormatDateToDateWithHyphens(expenses.getDate()) );
    xml.AddElem( "amount", AuxiliaryMethods::convertFloatToString(expenses.getAmount() ));

    xml.Save(FILE_NAME_WITH_EXPENSES);


}


vector <Expenses> FileWithExpenses::loadExpensesOfLoggedInUserFromFile(int loggedInUserId) {

    vector <Expenses> expensesVector;
    Expenses expenses;
    int userId = 0;
    int expensesId = 0;

    bool fileExists = xml.Load( FILE_NAME_WITH_EXPENSES );

    if(fileExists) {
        xml.FindElem("Expenses");
        xml.IntoElem();
        while(xml.FindElem("expenses")) {
            xml.IntoElem();
            xml.FindElem("expensesId");
            expensesId = AuxiliaryMethods::convertStringToInt(xml.GetData());
            xml.FindElem("userId");
            userId = AuxiliaryMethods::convertStringToInt(xml.GetData());
            if(userId == loggedInUserId) {
                expenses.setExpensesId(expensesId);
                expenses.setUserId(userId);
                xml.FindElem("item");
                expenses.setItem(xml.GetData());
                xml.FindElem("date");
                expenses.setDate(AuxiliaryMethods::changeFormatDateToInt(xml.GetData()));
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

