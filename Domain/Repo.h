//
// Created by alext on 04/04/2022.
//

#ifndef LAB_7_8_REPO_H
#define LAB_7_8_REPO_H


#include "Expense.h"
#include <vector>

using namespace std;

class Repo {
private:
    const int CAP = 1024;

    Expense* expenses;
    int noExpenses;
    int capacity;

    void resize();
public:
    /**
     * Constructor
     */
    Repo();

    /**
     * Constructor cu paramaetri
     * @param expenses
     * @param noExpenses
     * @param capacity
     */
    Repo(Expense* expenses, int noExpenses, int capacity);

    /**
     * Copy Constructor
     * @param r
     */
    Repo(const Repo& r);
    /**
     * Destructor
     */
    ~Repo();

    /**
     * Adauga un element
     * @param e , un element de tip cheltuiala
     */
    void addElem(Expense e);

    /**
     * Returneaza marimea array-ul
     * @return
     */
    int getSize();

    /**
     * Returneaza entitatea de pe pozitia pos
     * @param pos
     * @return
     */
    Expense getExpense(int pos);

    /**
     * Returneaza intr-un vector de tip Expense entitatile din repo
     * @return
     */
    vector<Expense> getAll();

    void updateExpense(int pos, Expense newExpense);

    /**
     * Sterge entitatea de pe pozitia pos
     * @param pos
     */
    void deleteExpense(int pos);

    Repo& operator=(const Repo& r);

};


#endif //LAB_7_8_REPO_H
