/*
# for polish notation
# [by Ica Riluci]
*/
#include <iostream>
#include <string>

using namespace std;

int p(char x) {
    switch (x) {
        case '+' :
        case '-' :
            return 1;
        case '*' :
        case '/' :
            return 2;
        default :
            return -1;
    }
}

void solve(string inp) {
    char *stack = new char[inp.length() * 2];
    int top = -1;
    for (int i = 0; i < inp.length(); ++i) {
        char c = inp[i];
        if (('a' <= c) && (c <= 'z'))
            cout << c;
        else {
            if (c == ')') {
                while (stack[top] != '(') {
                    cout << stack[top];
                    --top;
                }
                --top;
            }
            else {
                while ((top > -1) && (stack[top] != '(')) {
                    if (p(stack[top]) >= p(c)) {
                        cout << stack[top];
                        --top;
                    }
                    else
                        break;
                }
                stack[++top] = c;
            }
        }
    }
    while (top > -1)
        cout << stack[top--];
    cout << endl;
    delete []stack;
}

int main() {
    string inp;
    while (1) {
        cin >> inp;
        if (inp == "quit")
            break;
        solve(inp);
    }
    return 0;
}
