#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 12
#define MAXV 505

using namespace std;

int n, m;
int ansx[MAXN], g[MAXN], ans, ansl;
int f[MAXV];

int dp(int l) {
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    int maxw = 1;
    for (;;++maxw) {
        for (int i = 1; i <= l; ++i)
            if (maxw >= g[i])
                f[maxw] = min(f[maxw], f[maxw - g[i]] + 1);
        if (f[maxw] > n)
         return maxw - 1;
    }
}

void dfs(int cur) {
    int maxw = dp(cur);
    if ((maxw >= ans) && (cur == m)) {
        ans = maxw;
        ansl = cur;
        memcpy(ansx, g, sizeof(int) * (cur + 1));
    }
    if (cur == m)
        return;
    for (int i = g[cur] + 1; i <= maxw + 1; ++i) {
        g[cur + 1] = i;
        dfs(cur + 1);
    }
}

int main() {
    cin >> n >> m;
    g[1] = 1;
    dfs(1);
    for (int i = 1; i <= ansl; ++i)
        cout << ansx[i] << ' ';
    cout << endl;
    cout << "MAX=" << ans << endl;
    return 0;
}
