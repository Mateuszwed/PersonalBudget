#include <iostream>
#include "PersonalBudget.h"

using namespace std;

int main()
{
PersonalBudget personalBudget("Users.xml", "Incomes.xml", "Expenses.xml");

personalBudget.mainMenu();
}
