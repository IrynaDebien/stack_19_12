#pragma once
#include <iostream>
#include <conio.h>
#include <stack>
#include <cstring>
#include <windows.h>
using namespace std;

class BracketChecker {
private:
    char buffer[100];
    char errorMessage[70];
    stack<int> stk;
    int errorIndex;
    const char* inputString;
    char lastElement;

    int calculateStringLength(const char* str);
    bool checkStringEnd(const char* str, char lastElem);
    bool checkBrackets(const char* inputString, stack<int>& stk, int& errorIndex, char* errorMessage);
    bool checkRemainingBrackets(stack<int>& stk, int& errorIndex, char* errorMessage);
    
public:
    BracketChecker();
    void enterData();
    bool check();
    const char* getErrorMessage() const;
};