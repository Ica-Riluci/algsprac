/*
# designed for dfs learning
# [by Ica Riluci]
*/
#include <iostream>
#include <cstdlib>

using namespace std;

int queen[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
int map[8][8];

int def(int a, int b) {
    return (a > b) ? (a - b) : (b - a);
}

int retrieve(int depth, int plan[]) {
    if (depth == 8) {
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                map[i][j] = 0;
        for (int i = 0; i < 8; ++i)
            map[plan[i] / 8][plan[i] % 8] = 1;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j)
                if (map[i][j])
                    cout << 'Q';
                else
                    cout << '+';
            cout << endl;
        }
        return 0;
    }
    for (int i = 0; i < 8; ++i) {
        int pos = depth * 8 + i;
        int isvalid = 1;
        for (int j = 0; j < depth; ++j)
            if ((def(plan[j], pos) % 8 == 0) || (plan[j] / 8 == pos / 8) ||
        (def(plan[j] / 8, pos / 8) == def(plan[j] % 8, pos % 8))) {
                isvalid = 0;
                break;
            }
        if (isvalid) {
            plan[depth] = pos;
            retrieve(depth + 1, plan);
        }
    }
    return 0;
}

int main() {
    retrieve(0, queen);
    system("pause");
    return 0;
}
