#include "FileWithIncomes.h"


int FileWithIncomes::getLastIncomesId() {

    int lastId = 0;

    bool fileExists = xml.Load( FILE_NAME_WITH_INCOMES );
    if(fileExists) {
        xml.FindElem("Incomes");
        xml.IntoElem();
        while(xml.FindElem("incomes")) {
            xml.IntoElem();
            xml.FindElem("incomesId");
            lastId = AuxiliaryMethods::convertStringToInt(xml.GetData());
            xml.OutOfElem();
        }
    } else {
        lastId = 0;
    }
    return lastId;
}


void FileWithIncomes::addIncomesToFile(Incomes incomes) {

    bool fileExists = xml.Load( FILE_NAME_WITH_INCOMES );

    if(!fileExists) {

        xml.AddElem( "Incomes" );

    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "incomes" );
    xml.IntoElem();
    xml.AddElem( "incomesId", incomes.getIncomesId() );
    xml.AddElem( "userId", incomes.getUserId() );
    xml.AddElem( "item", incomes.getItem() );
    xml.AddElem( "date", AuxiliaryMethods::changeFormatDateToDateWithHyphens(incomes.getDate()) );
    xml.AddElem( "amount", AuxiliaryMethods::convertFloatToString(incomes.getAmount() ));

    xml.Save("Incomes.xml");


}


vector <Incomes> FileWithIncomes::loadIncomesOfLoggedInUserFromFile(int loggedInUserId) {

    vector <Incomes> incomesVector;
    Incomes incomes;
    int userId = 0;
    int incomesId = 0;

    bool fileExists = xml.Load( "Incomes.xml" );

    if(fileExists) {
        xml.FindElem("Incomes");
        xml.IntoElem();
        while(xml.FindElem("incomes")) {
            xml.IntoElem();
            xml.FindElem("incomesId");
            incomesId = AuxiliaryMethods::convertStringToInt(xml.GetData());
            xml.FindElem("userId");
            userId = AuxiliaryMethods::convertStringToInt(xml.GetData());
            if(userId == loggedInUserId) {
                incomes.setIncomesId(incomesId);
                incomes.setUserId(userId);
                xml.FindElem("item");
                incomes.setItem(xml.GetData());
                xml.FindElem("date");
                incomes.setDate(AuxiliaryMethods::changeFormatDateToInt(xml.GetData()));
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


