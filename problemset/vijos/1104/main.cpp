#define MAXT 2000
#define MAXM 100
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int t, m;
int cost[MAXM], val[MAXM], f[MAXT], vis[MAXT];

int main() {
    cin >> t >> m;
    for (int i = 0; i < m; ++i)
        cin >> cost[i] >> val[i];
    memset(f, 0, sizeof(f));
    memset(vis, 0, sizeof(vis));
    vis[0] = 1;
    int maxt = 0;
    for (int i = 0; i < m; ++i) {
        int tmpt = maxt;
        for (int j = maxt; j >= 0; --j)
            if (vis[j])
                if (j + cost[i] <= t) {
                    f[j + cost[i]] = max(f[j + cost[i]], f[j] + val[i]);
                    vis[j + cost[i]] = 1;
                    tmpt = max(tmpt, j + cost[i]);
                }
        maxt = tmpt;
    }
    int ans = 0;
    for (int i = t; i >= 0; --i)
        ans = max(f[i], ans);
    cout << ans << endl;
    return 0;
}
