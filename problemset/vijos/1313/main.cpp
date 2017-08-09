#define MAXV 50000
#define MAXN 100
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int v, n;
int vol[MAXN], val[MAXN];
int son[MAXN][3], father[MAXN];
int visited[MAXV];
int f[MAXV];

int main() {
    cin >> v >> n;
    memset(son, 0, sizeof(son));
    memset(f, 0, sizeof(f));
    memset(visited, 0, sizeof(f));
    for (int i = 0; i < n; ++i) {
        cin >> vol[i] >> val[i] >> father[i];
        --father[i];
        val[i] *= vol[i];
        if (father[i] != -1) {
            ++son[father[i]][0];
            son[father[i]][son[father[i]][0]] = i;
        }
    }
    int maxv = 0, ans = 0;
    visited[0] = 1;
    for (int i = 0; i < n; ++i) {
        if (father[i] != -1)
            continue;
        int tmp = maxv;
        for (int j = maxv; j >= 0; --j)
            if (visited[j])
                if (j + vol[i] <= v) {
                    visited[j + vol[i]] = 1;
                    f[j + vol[i]] = max(f[j + vol[i]], f[j] + val[i]);
                    tmp = max(tmp, j + vol[i]);
                    for (int k = 1; k <= son[i][0]; ++k)
                        if (j + vol[i] + vol[son[i][k]] <= v) {
                            visited[j + vol[i] + vol[son[i][k]]] = 1;
                            f[j + vol[i] + vol[son[i][k]]] = max(f[j + vol[i] + vol[son[i][k]]], f[j] + val[i] + val[son[i][k]]);
                            tmp = max(tmp, j + vol[i] + vol[son[i][k]]);
                        }
                    if (son[i][0] == 2)
                        if (j + vol[i] + vol[son[i][1]] + vol[son[i][2]] <= v) {
                            visited[j + vol[i] + vol[son[i][1]] + vol[son[i][2]]] = 1;
                            f[j + vol[i] + vol[son[i][1]] + vol[son[i][2]]] = max(f[j + vol[i] + vol[son[i][1]] + vol[son[i][2]]], f[j] + val[i] + val[son[i][1]] + val[son[i][2]]);
                            tmp = max(tmp, j + vol[i] + vol[son[i][1]] + vol[son[i][2]]);
                        }
                }
        maxv = tmp;
    }
    for (int i = 0; i <= v; ++i)
        ans = max(ans, f[i]);
    cout << ans << endl;
    return 0;
}
