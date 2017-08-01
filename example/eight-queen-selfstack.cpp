/*
# designed for stack practice
# [by Ica Riluci]
*/
#include <iostream>
#include <cstdlib>

using namespace std;

int dstack[20];
int istack[20];
int pstack[20][8];
int top = 0;
int map[8][8];

int def(int a, int b) { return (a > b) ? (a - b) : (b - a);}

int main() {
    dstack[0] = 0;
    istack[0] = -1;
    for (int i = 0; i < 8; ++i) pstack[0][i] = -1;
    while (top > -1) {
        if (dstack[top] == 8) {
            for (int i = 0; i < 8; ++i)
                for (int j = 0; j < 8; ++j)
                    map[i][j] = 0;
            for (int i = 0; i < 8; ++i)
                map[pstack[top][i] / 8][pstack[top][i] % 8] = 1;
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j)
                    if (map[i][j])
                        cout << 'Q';
                    else
                        cout << '+';
                cout << endl;
            }
            --top;
            continue;
        }
        if (istack[top] == 8) {
            --top;
            continue;
        }
        int pos = dstack[top] * 8 + (istack[top] + 1);
        int isvalid = 1;
        for (int i = 0; i < dstack[top]; ++i)
            if ((def(pstack[dstack[top]][i], pos) % 8 == 0) || (pstack[dstack[top]][i] / 8 == pos / 8) ||
        (def(pstack[dstack[top]][i] / 8, pos / 8) == def(pstack[dstack[top]][i] % 8, pos % 8))) {
                isvalid = 0;
                break;
            }
        if (isvalid) {
            for (int i = 0; i < 8; ++i)
                pstack[top + 1][i] = pstack[top][i];
            pstack[top + 1][dstack[top]] = pos;
            istack[top + 1] = -1;
            dstack[top + 1] = dstack[top] + 1;
            ++istack[top];
            ++top;
        }
        else
            ++istack[top];
    }
    system("pause");
    return 0;
}
