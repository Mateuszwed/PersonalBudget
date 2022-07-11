#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Markup.h"
#include "Incomes.h"
#include "AuxiliaryMethods.h"
#include "BalanceManager.h"


class FileWithIncomes {

const string FILE_NAME_WITH_INCOMES;

public:

    FileWithIncomes(string fileNameWithIncomes) : FILE_NAME_WITH_INCOMES(fileNameWithIncomes) {}

    int getLastIncomesId();
    void addIncomesToFile(Incomes incomes);
    vector <Incomes> loadIncomesOfLoggedInUserFromFile(int loggedInUserId);
};

#endif
