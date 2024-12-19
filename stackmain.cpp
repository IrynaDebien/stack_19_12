#include "stack.h"

int main() {
    SetConsoleCP(1251);  
    SetConsoleOutputCP(1251); 
    cout << "Bracket Checker" << endl;
    BracketChecker checker;
    checker.enterData();
    if (checker.check()) {
        cout << "String is correct" << endl;
    }
    else {
        cout << "Error: " << checker.getErrorMessage() << endl;
    }

    return 0;
}
