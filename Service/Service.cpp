//
// Created by alext on 12/04/2022.
//

#include <cstring>
#include <algorithm>
#include "Service.h"

Service::Service() {
    this->repo = Repo();
}

Service::Service(const Repo &repo) {
    this->repo = repo;
}

void Service::addExpense(Expense ex) {
    this->repo.addElem(ex);
}

void Service::updateExpense(int pos, Expense newExpense) {
    this->repo.updateExpense(pos, newExpense);
}

vector<Expense> Service::getAll() {
    vector<Expense> rez = repo.getAll();
    return rez;
}

vector<Expense> Service::getAllByNoAp(int noAp) {
    vector<Expense> rez;
    for(auto item: repo.getAll()){
        if(item.getNoAp() == noAp)
           rez.push_back(item);
    }
    return rez;
}

vector<Expense> Service::getAllbyOperAndSum(char oper, int sum) {
    vector<Expense> rez;
    if(oper == '<'){
        for(auto item: repo.getAll()){
            if(item.getSum() < sum)
                rez.push_back(item);
        }
    }
    else if(oper == '>'){
        for(auto item: repo.getAll()){
            if(item.getSum() > sum)
                rez.push_back(item);
        }
    }
    else {
        for(auto item: repo.getAll()){
            if(item.getSum() == sum)
                rez.push_back(item);
        }
    }

    return rez;
}

int Service::sumOfExpenses(string type) {
    int sum = 0;
    char* tp = const_cast<char*>(type.c_str());
    for(auto item: repo.getAll()){
        if(strcmp(item.getType(), tp) == 0)
            sum += item.getSum();
    }
    return sum;
}

Expense Service::getBigggestExpenseOfNoAp(int noAp) {
    Expense max;
    for(auto item: repo.getAll()){
        if(item.getNoAp() == noAp){
            if (max < item) { max = item; }
        }
    }
    return max;
}

vector<Expense> Service::sortDescByType(string type) {
    vector<Expense> rez;
    char* tp = const_cast<char*>(type.c_str());
    for(auto item: repo.getAll()){
        if(strcmp(item.getType(), tp) == 0)
            rez.push_back(item);
    }
    sort(rez.rbegin(), rez.rend());
    return rez;
}

void Service::filterByType(string type) {
    vector<Expense> rez;
    char* tp = const_cast<char*>(type.c_str());

    for(auto item: repo.getAll()){
        if(strcmp(item.getType(), tp) == 0)
            rez.push_back(item);
    }
    this->clearAll();
    for(auto item: rez){
        repo.addElem(item);
    }
}

void Service::filterByASum(int sum) {
    vector<Expense> rez;
    for(auto item: repo.getAll()){
        if(item.getSum() < sum)
            rez.push_back(item);
    }
    clearAll();
    for(auto item: rez){
        repo.addElem(item);
    }
}

void Service::clearAll() {
    while(repo.getSize() != 0){
        repo.deleteExpense(0);
    }
}


