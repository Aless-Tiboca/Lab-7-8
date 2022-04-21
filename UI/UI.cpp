//
// Created by alext on 18/04/2022.
//

#include "UI.h"
#include <iostream>

using namespace std;


void UI::printEntities(vector<Expense> entities) {
    for(auto item: entities){
        cout<<item<<endl;
    }
    cout<<endl;
}


void UI::printOptions() {
    cout<<"1.Adaugare cheltuieli"<<endl;
    cout<<"2.Afisare cheltuieli"<<endl;
    cout<<"3.Suma totala a unui tip de cheltuiala"<<endl;
    cout<<"4.Afisarea celei mai mari cheltuieli a unui apartament"<<endl;
    cout<<"5.Afisarea descrescatoare a cheltuielilor de un tip anume"<<endl;
    cout<<"6.Filtreaza toate cheltuielile dupa un tip anume"<<endl;
    cout<<"7.Filtreaza toate cheltuielile mai mici decat o suma data"<<endl;
    cout<<"u.Undo"<<endl;
    cout<<"x.Iesire"<<endl;
}

UI::UI(const Service &service) {
    this->service = Service();
}

void UI::readEntity() {
    undoVector = this->service.getAll();
    int n=0;
    string type;
    unsigned int nrAp, suma;
    cout<<"Dati numarul de cheltuieli pe care doriti sa le adaugati: "<<endl;
    cin>>n;
    cout<<"Dati cheltuielile sub forma ([nrApartament] [tipCheltuiala] [suma]):"<<endl;
    for(int i=0; i<n; i++){
        cin>>nrAp>>type>>suma;
        char* tp = const_cast<char*>(type.c_str());
        Expense ex(nrAp, suma, tp);
        this->service.addExpense(ex);
    }
}

void UI::runMenu() {
    char option;
    bool ok = true;
    int n=0;
    while(ok)
    {
        printOptions();
        cout<<"Dati o optiune: "<<endl;
        cin>>option;
        switch(option)
        {
            case '1': {
                readEntity();
                break;
            }
            case '2': {
                runOption2();
                break;
            }
            case '3':{
                displaySumOfAType();
                break;
            }
            case '4':{
                displayBiggestSumOfNoAp();
                break;
            }
            case '5':{
                displayDescExpensesOfAType();
                break;
            }
            case '6':{
                displayFilteredByType();
                break;
            }
            case '7':{
                displayFilteredLowerThanANumber();
                break;
            }
            case 'u':{
                undo();
                break;
            }
            case 'x':{
                ok = false;
                break;
            }
            default:{
                cout<<"Optiunea aleasa este gresita!"<<endl;
                break;
            }

        }
    }

}

void UI::printDisplayOptions() {
    cout<<"     1.Afisare tuturor cheltuielilor"<<endl;
    cout<<"     2.Afisarea tuturor cheltuielilor apartinand unui apartament"<<endl;
    cout<<"     3.Afisarea tuturor cheltuielilor cu filtru (<, >, =) in functie de suma"<<endl;
}

void UI::runOption2() {
    char option2;
    printDisplayOptions();
    cin >> option2;
    switch (option2) {
        case '1': {
            printEntities(this->service.getAll());
            break;
        }
        case '2': {
            int noAp;
            cout << "Dati numarul apartmentului: " << endl;
            cin >> noAp;
            printEntities(this->service.getAllByNoAp(noAp));
            break;
        }
        case '3': {
            int sum;
            char op;
            cout << "Dati operatorul si suma dupa care doriti sa filtrati: " << endl;
            cin >> op >> sum;
            printEntities(this->service.getAllbyOperAndSum(op, sum));
            break;
        }
        default: {
            cout << "Optiunea aleasa nu este valida!" << endl;
            break;
        }
    }
}

void UI::displaySumOfAType() {
    string type;
    cout<<"Dati tipul de factura pentru care doriti suma: "<<endl;
    cin>>type;
    cout<<"Suma tuturor facturilor de tipul "<<type<<" este: "<<this->service.sumOfExpenses(type)<<endl;
}

void UI::displayBiggestSumOfNoAp() {
    int noAp;
    cout<<"Dati numarul apartamentului"<<endl;
    cin>>noAp;
    cout<<"Cea mai valoroasa cheltuiala a apartamentului "<<noAp<<" este: "<< this->service.getBigggestExpenseOfNoAp(noAp)<<endl;
}

void UI::displayDescExpensesOfAType() {
    string type;
    cout<<"Dati tipul de factura pe care doriti sa le ordonati: "<<endl;
    cin>>type;
    vector<Expense> rez = this->service.sortDescByType(type);
    printEntities(rez);
}

void UI::displayFilteredByType() {
    undoVector = this->service.getAll();
    string type;
    cout<<"Dati tipul de factura pe care doriti sa le filtrati: "<<endl;
    cin>>type;
    this->service.filterByType(type);
    printEntities(this->service.getAll());
}

void UI::displayFilteredLowerThanANumber() {
    undoVector = this->service.getAll();
    int sum;
    cout<<"Dati suma dupa care doriti sa filtrati: "<< endl;
    cin>>sum;
    this->service.filterByASum(sum);
    printEntities(this->service.getAll());
}

void UI::undo() {
    this->service.clearAll();
    for(auto item: undoVector){
        this->service.addExpense(item);
    }
    undoVector.clear();
}

