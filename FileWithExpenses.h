#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Markup.h"
#include "Expenses.h"
#include "AuxiliaryMethods.h"

class FileWithExpenses {

const string FILE_NAME_WITH_EXPENSES;
CMarkup xml;

public:

    FileWithExpenses(string fileNameWithExpenses) : FILE_NAME_WITH_EXPENSES(fileNameWithExpenses) {}

    int getLastExpensesId();
    void addExpensesToFile(Expenses expenses);
    vector <Expenses> loadExpensesOfLoggedInUserFromFile(int loggedInUserId);
};

#endif
