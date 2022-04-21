//
// Created by alext on 04/04/2022.
//

#include "Repo.h"
#include <iostream>


Repo::Repo() {
    this->capacity = CAP;
    this->expenses = new Expense[capacity];
    this->noExpenses = 0;
}

Repo::Repo(Expense *expenses, int noExpenses, int capacity) {
    this->noExpenses = noExpenses;
    this->capacity = capacity;
    this->expenses = new Expense[capacity];
    for(int i=0; i<this->noExpenses; i++){
        this->expenses[i] = expenses[i];
    }
}

Repo::Repo(const Repo &r) {
    this->capacity = r.capacity;
    this->noExpenses = r.noExpenses;
    this->expenses = new Expense[capacity];
    for(int i=0; i<this->noExpenses; i++){
        this->expenses[i] = r.expenses[i];
    }
}

Repo::~Repo() {
    delete[] this->expenses;
    this->noExpenses = 0;
    this->capacity = 0;
}

void Repo::addElem(Expense e) {
    if(this->noExpenses == this->capacity){
        this->resize();
    }
    this->expenses[noExpenses++] = e;
}

void Repo::resize() {
    capacity = capacity + CAP;
    auto* newExpenses = new Expense[capacity];

    for (int i=0; i < noExpenses; i++) {
        newExpenses[i] = expenses[i];
    }
    delete[] expenses;
    expenses = newExpenses;
}

int Repo::getSize() {
    return this->noExpenses;
}

Expense Repo::getExpense(int pos) {
    if(pos>=0 && pos<this->noExpenses)
        return this->expenses[pos];
}

vector<Expense> Repo::getAll() {
    vector<Expense> rez;
    rez.reserve(this->noExpenses);
    for(int i=0; i<this->noExpenses;i++)
        rez.push_back(this->expenses[i]);
    return rez;
}

Repo& Repo::operator=(const Repo &r) {
    this->capacity = r.capacity;
    this->noExpenses = r.noExpenses;
    this->expenses = new Expense[capacity];
    for(int i=0; i<this->noExpenses; i++){
        this->expenses[i] = r.expenses[i];
    }
}

void Repo::deleteExpense(int pos) {
    Expense* newExpenses = new Expense[this->noExpenses];
    int j=0;
    for(int i=0;i<this->noExpenses;i++){
        if(i!=pos){
            newExpenses[j++] = expenses[i];
        }
    }
    delete[] expenses;
    expenses = newExpenses;
    this->noExpenses--;
}

void Repo::updateExpense(int pos, Expense newExpense) {
    this->expenses[pos] = newExpense;
}





