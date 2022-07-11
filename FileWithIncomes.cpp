#include "FileWithIncomes.h"


int FileWithIncomes::getLastIncomesId() {

    CMarkup xml;

    int lastId = 0;

    bool fileExists = xml.Load( FILE_NAME_WITH_INCOMES );
    if(fileExists) {
        xml.FindElem("Incomes");
        xml.IntoElem();
        while(xml.FindElem("income")) {
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


void FileWithIncomes::addIncomesToFile(Incomes incomes) {

    CMarkup xml;

    bool fileExists = xml.Load( FILE_NAME_WITH_INCOMES );

    if(!fileExists) {

        xml.AddElem( "Incomes" );

    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "income" );
    xml.IntoElem();
    xml.AddElem( "id", incomes.getId() );
    xml.AddElem( "userId", incomes.getUserId() );
    xml.AddElem( "item", incomes.getItem() );
    xml.AddElem( "date", BalanceManager::changeFormatDateToDateWithHyphens(incomes.getDate()) );
    xml.AddElem( "amount", AuxiliaryMethods::convertFloatToString(incomes.getAmount() ));

    xml.Save("Incomes.xml");


}


vector <Incomes> FileWithIncomes::loadIncomesOfLoggedInUserFromFile(int loggedInUserId) {

    CMarkup xml;

    vector <Incomes> incomesVector;
    Incomes incomes;
    int userId = 0;
    int id = 0;

    bool fileExists = xml.Load( "Incomes.xml" );

    if(fileExists) {
        xml.FindElem("Incomes");
        xml.IntoElem();
        while(xml.FindElem("income")) {
            xml.IntoElem();
            xml.FindElem("id");
            id = AuxiliaryMethods::convertStringToInt(xml.GetData());
            xml.FindElem("userId");
            userId = AuxiliaryMethods::convertStringToInt(xml.GetData());
            if(userId == loggedInUserId) {
                incomes.setId(id);
                incomes.setUserId(userId);
                xml.FindElem("item");
                incomes.setItem(xml.GetData());
                xml.FindElem("date");
                incomes.setDate(BalanceManager::changeFormatDateToInt(xml.GetData()));
                xml.FindElem("amount");
                incomes.setAmount(AuxiliaryMethods::convertStringToFloat(xml.GetData()));
                xml.OutOfElem();
                incomesVector.push_back(incomes);

            } else {
                xml.OutOfElem();
            }
        }

    }
    return incomesVector;
}


