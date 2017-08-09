#define MAXV 50000
#define MAXN 50
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int vol[MAXN], val[MAXN];
int f[MAXV], visited[MAXV];
int v, n;

int main() {
    cin >> v >> n;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> vol[i] >> tmp;
        val[i] = vol[i] * tmp;
    }
    memset(f, 0, sizeof(f));
    memset(visited, 0, sizeof(visited));
    int maxv = 0;
    visited[0] = 1;
    for (int i = 0; i < n; ++i) {
        int tmp = maxv;
        for (int j = maxv; j >= 0; --j)
            if (visited[j])
                if (j + vol[i] <= v) {
                    visited[j + vol[i]] = 1;
                    f[j + vol[i]] = max(f[j + vol[i]], f[j] + val[i]);
                    tmp = max(tmp, j + vol[i]);
                }
        maxv = tmp;
    }
    int ans = 0;
    for (int i = 0; i <= v; ++i)
        ans = max(ans, f[i]);
    cout << ans << endl;
    return 0;
}
