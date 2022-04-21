//
// Created by alext on 12/04/2022.
//

#ifndef LAB_7_8_SERVICE_H
#define LAB_7_8_SERVICE_H

#include "../Domain/Repo.h"

class Service {
private:
    Repo repo;

public:
    Service();
    Service(const Repo &repo);

    void addExpense(Expense ex);
    void updateExpense(int pos, Expense newExpense);
    vector<Expense> getAll();
    vector<Expense> getAllByNoAp(int noAp);
    vector<Expense> getAllbyOperAndSum(char oper, int sum);
    int sumOfExpenses(string type);
    Expense getBigggestExpenseOfNoAp(int noAp);
    vector<Expense> sortDescByType(string type);
    void filterByType(string type);
    void filterByASum(int sum);
    void clearAll();

};


#endif //LAB_7_8_SERVICE_H
