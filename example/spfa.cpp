/*
# practice for spfa
# [by Ica Riluci]
*/
#include <iostream>
#include <cstdlib>
#include <climits>
#define maxn 1000

using namespace std;

int dis[maxn];
int map[maxn][maxn];
int n. m;
int que[maxn * 2];
int inque[maxn];
int head = -1, tail = 0;
int start;

void  init() {
    cin >> n >> m;
    for (i = 0; i < n; ++i) {
        dis[i] = INT_MAX;
        for (j = 0; j < n; ++j)
            map[i][j] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int x, y, l;
        cin >> x >> y >> l;
        map[x][y] = l;
        map[y][x] = l;
    }
    for (int i = 0; )
    cin >> start;
}

int spfa() {
    que[0] = start;
    while head != tail {
        ++head;
        head %= maxn * 2;
        int p = que[head];
        for (int i = 0; i < n; ++i) {
            if (map[p][i] > 0) {
                if (dis[i] < dis[p] + map[p][i]) {
                    dis[i] = dis[p] + map[p][i];
                    if (inque[i] == 0) {
                        ++tail;
                        tail %= maxn * 2;
                        que[tail] = i;
                        inque[i] = 1;
                    }
                }
            }
        }
        inque[p] = 0;
    }
}

int main() {
    init();
    spfa();
    while (1) {
        int t;
        cin >> t;
        cout << dis[t] << endl;
    }
    return 0;
}
