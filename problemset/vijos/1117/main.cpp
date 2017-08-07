#include <iostream>
#define MAXN 220
#define MAXK 6

using namespace std;

int n, k;
int f[MAXN][MAXK + 1][MAXN];

int floordiv(int divi, int fac) {
    if (divi % fac != 0)
        return divi / fac + 1;
    else
        return divi / fac;
}

int min(int a, int b) {
    if (a < b)
        return a;
    return b;
}

int main() {
    //init
    cin >> n >> k;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            for (int l = 0; l <= k; ++l)
                f[i][l][j] = 0;
    for (int i = 1; i <= n; ++i)
        f[i][1][i] = 1;
    //solve
    for (int l = 2; l <= k; ++l)
        for (int i = 1; i <= n; ++i) {
            int blim = floordiv(i, l);
            int ulim = i - l + 1;
            for (int j = blim; j <= ulim; ++j) {
                int bolim = floordiv(i - j, l - 1);
                int uplim = min(j, i - l - j + 2);
                f[i][l][j] = 0;
                for (int v = bolim; v <= uplim; ++v)
                    f[i][l][j] += f[i - j][l - 1][v];
            }
        }
    int ans = 0;
    int blim = floordiv(n, k);
    int ulim = n - k + 1;
    for (int i = blim; i <= ulim; ++i)
        ans += f[n][k][i];
    cout << ans << endl;
    return 0;
}
