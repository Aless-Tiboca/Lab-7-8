#include <iostream>
#include "Tests/tests.h"
#include "UI/UI.h"

using namespace std;

int main() {
    testAll();
    Service service;
    UI ui(service);
    ui.runMenu();

    return 0;
}
