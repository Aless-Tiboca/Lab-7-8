//
// Created by alext on 04/04/2022.
//

#include <cassert>
#include <iostream>
#include "tests.h"
#include "../Domain/Expense.h"
#include "../Domain/Repo.h"
#include "../Service/Service.h"

void testAll() {
    testExpensesGetSet();
    testRepo();
    testService();
}

void testExpensesGetSet() {
    Expense ex;
    ex.setNoAp(15);
    assert(ex.getNoAp()==15);
    ex.setNoAp(20);
    assert(ex.getNoAp()==20);
    ex.setSum(2000);
    assert(ex.getSum()==2000);
    ex.setSum(203);
    assert(ex.getSum()==203);
    char* c = (char*)"gaz";
    ex.setType(c);
    assert(*ex.getType()=='g');
    c = (char*)"apa";
    ex.setType(c);
    assert(ex.getType()[0]=='a');
}

void testRepo() {
    Repo r;
    // test addElem

    for(int i=0; i<5; i++){
        Expense e(i, 200+40*i, (char*)"gaz");
        r.addElem(e);
    }
    //test getExpense

    Expense test(0, 200, (char*)"gaz");
    assert(r.getExpense(0) == test);
    Expense test1(1, 240, (char*)"gaz");
    assert(r.getExpense(1) == test1);

    //test getSize()

    assert(r.getSize() == 5);
    r.addElem(Expense(6, 466, (char*)"ceva"));
    assert(r.getSize() == 6);

    //test getAll()

    vector<Expense> all;
    all = r.getAll();
    assert(r.getExpense(0) == all[0]);
    assert(r.getExpense(2) == all[2]);
    assert(r.getExpense(3) == all[3]);


    //test updateExpense()

    Repo repo;
    repo.addElem(Expense(1, 345, (char*)"gaz"));
    repo.addElem(Expense(4, 45, (char*)"apa"));
    repo.addElem(Expense(3, 325, (char*)"curent"));
    repo.addElem(Expense(5, 335, (char*)"internet"));

    assert(repo.getSize()==4);
    repo.updateExpense(1, Expense(22, 1000, (char*)"noua apa"));
    assert(repo.getExpense(1).getNoAp()==22);
    assert(repo.getExpense(1).getSum()==1000);
    assert(*repo.getExpense(1).getType()=='n');

    //test deleteExpense()

    repo.deleteExpense(0);
    assert(repo.getSize()==3);

}

void testService() {
    testServiceAdd();
    testServiceClearAll();
    testServiceUpdate();
    testServiceGetAll();
    testServiceGetAllNoAp();
    testServiceGetAllOper();
    testServiceSumExpenses();
    testServiceBiggestExpense();
    testServiceSortDesc();
    testServiceFilterType();
    testServiceFilerSum();

}

void testServiceAdd() {
    Repo repo;
    Service ser(repo);
    Expense ex(1, 345, (char*)"gaz");
    ser.addExpense(ex);
    ser.addExpense(Expense(4, 45, (char*)"apa"));
    ser.addExpense(Expense(3, 325, (char*)"curent"));
    ser.addExpense(Expense(5, 335, (char*)"internet"));
    assert(ser.getAll().size() == 4);
}

void testServiceUpdate() {
    Repo repo;
    Service ser(repo);
    Expense ex(1, 345, (char*)"gaz");
    ser.addExpense(Expense(4, 45, (char*)"apa"));
    ser.updateExpense(0, ex);
    assert(ser.getAll()[0].getSum() == 345);
    assert(ser.getAll()[0].getNoAp() == 1);
}

void testServiceClearAll() {
    Service ser;
    ser.addExpense(Expense(4, 45, (char*)"apa"));
    ser.addExpense(Expense(3, 325, (char*)"curent"));
    ser.addExpense(Expense(5, 335, (char*)"internet"));
    ser.clearAll();
    assert(ser.getAll().size() == 0);
}

void testServiceGetAll() {
    Service ser;
    ser.addExpense(Expense(4, 45, (char*)"apa"));
    ser.addExpense(Expense(3, 325, (char*)"curent"));
    ser.addExpense(Expense(5, 335, (char*)"internet"));
    vector<Expense> rez = ser.getAll();
    assert(rez.size() == 3);
}

void testServiceGetAllNoAp() {
    Service ser;
    ser.addExpense(Expense(3, 45, (char*)"apa"));
    ser.addExpense(Expense(3, 325, (char*)"apa"));
    ser.addExpense(Expense(5, 335, (char*)"internet"));
    vector<Expense> rez = ser.getAllByNoAp(3);
    assert(rez.size() == 2);
}

void testServiceGetAllOper() {
    Service ser;
    ser.addExpense(Expense(3, 45, (char*)"apa"));
    ser.addExpense(Expense(3, 325, (char*)"apa"));
    ser.addExpense(Expense(5, 335, (char*)"internet"));
    vector<Expense> rez = ser.getAllbyOperAndSum('=', 45);
    assert(rez.size() == 1);
}

void testServiceSumExpenses() {
    Service ser;
    ser.addExpense(Expense(3, 45, (char*)"apa"));
    ser.addExpense(Expense(3, 325, (char*)"apa"));
    ser.addExpense(Expense(5, 335, (char*)"internet"));
    assert(ser.sumOfExpenses("apa") == 370);
}

void testServiceBiggestExpense() {
    Service ser;
    ser.addExpense(Expense(3, 45, (char*)"apa"));
    ser.addExpense(Expense(3, 325, (char*)"apa"));
    ser.addExpense(Expense(5, 335, (char*)"internet"));
    assert(ser.getBigggestExpenseOfNoAp(3) == Expense(3, 325, (char*)"apa"));
}

void testServiceSortDesc() {
    Service ser;
    ser.addExpense(Expense(3, 45, (char*)"apa"));
    ser.addExpense(Expense(3, 325, (char*)"apa"));
    ser.addExpense(Expense(5, 335, (char*)"internet"));
    vector<Expense> rez = ser.sortDescByType("apa");
    assert(rez.size() == 2);
    assert(rez[0] == Expense(3, 325, (char*)"apa"));
    assert(rez[1] == Expense(3, 45, (char*)"apa"));
}

void testServiceFilterType() {
    Service ser;
    ser.addExpense(Expense(3, 45, (char*)"apa"));
    ser.addExpense(Expense(3, 325, (char*)"apa"));
    ser.addExpense(Expense(5, 335, (char*)"internet"));
    ser.filterByType("apa");
    assert(ser.getAll().size() == 2);
}

void testServiceFilerSum() {
    Service ser;
    ser.addExpense(Expense(3, 45, (char*)"apa"));
    ser.addExpense(Expense(3, 325, (char*)"apa"));
    ser.addExpense(Expense(5, 335, (char*)"internet"));
    ser.filterByASum(300);
    assert(ser.getAll().size() == 1);
}

