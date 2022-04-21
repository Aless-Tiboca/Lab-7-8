//
// Created by alext on 04/04/2022.
//

#ifndef LAB_7_8_EXPENSE_H
#define LAB_7_8_EXPENSE_H


#include <ostream>

class Expense {
private:
    unsigned int noAp, sum;
    char* type;

public:
    Expense();
    Expense(int noAp, int sum, char* type);
    Expense(const Expense &ex);


    unsigned int getNoAp() const;

    virtual ~Expense();

    void setNoAp(unsigned int noAp);

    unsigned int getSum() const;

    void setSum(unsigned int sum);

    char *getType() const;

    void setType(char *type);

    Expense& operator=(const Expense& ex);

    bool operator<(const Expense &rhs) const;

    bool operator>(const Expense &rhs) const;

    bool operator<=(const Expense &rhs) const;

    bool operator>=(const Expense &rhs) const;

    bool operator==(const Expense &rhs) const;

    bool operator!=(const Expense &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Expense &expense);

};


#endif //LAB_7_8_EXPENSE_H
