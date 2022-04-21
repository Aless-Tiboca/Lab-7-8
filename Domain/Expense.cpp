//
// Created by alext on 04/04/2022.
//

#include "Expense.h"
#include <cstring>

Expense::Expense() {
    this->noAp = 0;
    this->sum = 0;
    this->type = nullptr;
}

Expense::Expense(int noAp, int sum, char *type) {
    this->noAp = noAp;
    this->sum = sum;
    this->type = new char[strlen(type)+1];
    strcpy_s(this->type, strlen(type)+1, type);
}

Expense::Expense(const Expense &ex) {
    this->type = new char[strlen(ex.type)+1];
    strcpy_s(this->type, strlen(ex.type)+1, ex.type);
    this->noAp = ex.noAp;
    this->sum = ex.sum;
}

unsigned int Expense::getNoAp() const {
    return noAp;
}

void Expense::setNoAp(unsigned int noAp) {
    Expense::noAp = noAp;
}

unsigned int Expense::getSum() const {
    return sum;
}

void Expense::setSum(unsigned int sum) {
    Expense::sum = sum;
}

char *Expense::getType() const {
    return type;
}

void Expense::setType(char *type) {
    if (!this->type){
        delete[] this->type;
    }
    this->type = new char[strlen(type)+1];
    strcpy_s(this->type, strlen(type)+1, type);
}

Expense::~Expense() {
    delete[] this->type;
    this->noAp = 0;
    this->sum = 0;

}

Expense& Expense::operator=(const Expense& ex) {
    if(this != &ex){
        this->noAp = ex.noAp;
        this->sum = ex.sum;
        this->setType(ex.type);
    }

    return *this;
}

bool Expense::operator==(const Expense &rhs) const {
    return (noAp == rhs.noAp &&
           sum == rhs.sum &&
            strcmp(type, rhs.type)==0);
}

bool Expense::operator!=(const Expense &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const Expense &expense) {
    os << "noAp: " << expense.noAp << " sum: " << expense.sum << " type: " << expense.type;
    return os;
}

bool Expense::operator<(const Expense &rhs) const {
    return (sum < rhs.sum);
}

bool Expense::operator>(const Expense &rhs) const {
    return rhs < *this;
}

bool Expense::operator<=(const Expense &rhs) const {
    return !(rhs < *this);
}

bool Expense::operator>=(const Expense &rhs) const {
    return !(*this < rhs);
}
