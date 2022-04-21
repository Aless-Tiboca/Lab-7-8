//
// Created by alext on 18/04/2022.
//

#ifndef LAB5_UI_H
#define LAB5_UI_H

#include "../Service/Service.h"

class UI{
private:
    Service service;

    void printEntities(vector<Expense> entities);

    void printOptions();
    void printDisplayOptions();
    void runOption2();

    vector<Expense> undoVector;
public:


    UI(const Service &service);

    void readEntity();

    void displaySumOfAType();

    void displayBiggestSumOfNoAp();

    void displayDescExpensesOfAType();

    void displayFilteredByType();

    void displayFilteredLowerThanANumber();

    void undo();

    void runMenu();
};

#endif //LAB5_UI_H
