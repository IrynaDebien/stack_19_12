#include "stack.h"

int BracketChecker::calculateStringLength(const char* str) {
    return static_cast<int>(strlen(str));
}

bool BracketChecker::checkStringEnd(const char* str, char lastElem) {
    int strLen = calculateStringLength(str);
    return (str[strLen - 1] == lastElem);
}

bool BracketChecker::checkBrackets(const char* inputString, stack<int>& stk, int& errorIndex, char* errorMessage) {
    for (int i = 0; inputString[i] != '\0'; i++) {
        if (inputString[i] == '(' || inputString[i] == '{' || inputString[i] == '[') {
            stk.push(i);
        }
        else if (inputString[i] == ')' || inputString[i] == '}' || inputString[i] == ']') {
            if (stk.empty()) {
                errorIndex = i;
                snprintf(errorMessage, sizeof(errorMessage), "No opening bracket for closing bracket at position %d", i);
                return false;
            }
            char topBracket = inputString[stk.top()];
            if ((inputString[i] == ')' && topBracket != '(') ||
                (inputString[i] == '}' && topBracket != '{') ||
                (inputString[i] == ']' && topBracket != '[')) {
                errorIndex = i;
                snprintf(errorMessage, sizeof(errorMessage), "Mismatch of brackets at position %d", i);
                return false;
            }
            stk.pop();  // Remove the index of the opening bracket from the stack
        }
    }
    return true;
}

bool BracketChecker::checkRemainingBrackets(stack<int>& stk, int& errorIndex, char* errorMessage) {
    if (!stk.empty()) {
        errorIndex = stk.top();
        snprintf(errorMessage, sizeof(errorMessage), "No closing bracket for opening bracket at position %d", errorIndex);
        return false;
    }
    return true;
}





BracketChecker::BracketChecker() : inputString(""), errorIndex(-1), lastElement(';') {
    strcpy_s(errorMessage, sizeof(errorMessage), "error");
    buffer[0] = '\0';
}

void BracketChecker::enterData() {
    cout << "Enter a string with different brackets (the string must end with ';'): ";
    cin.getline(buffer, 100);
    inputString = buffer;
}

bool BracketChecker::check() {
    if (!checkStringEnd(inputString, lastElement)) {
        strcpy_s(errorMessage, sizeof(errorMessage), "Error: the string must end with ';'");
        return false;
    }

    if (!checkBrackets(inputString, stk, errorIndex, errorMessage)) {
        return false;
    }

    if (!checkRemainingBrackets(stk, errorIndex, errorMessage)) {
        return false;
    }

    strcpy_s(errorMessage, sizeof(errorMessage), "String is correct");
    return true;
}

const char* BracketChecker::getErrorMessage() const {
    return errorMessage;
}