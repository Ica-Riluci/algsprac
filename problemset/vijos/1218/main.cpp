#define MAXN 200
#define MAXM 15
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <climits>

using namespace std;

int n, m;
int data[MAXN];
int sum[MAXN];
int f[MAXN][MAXN][MAXM];

int mod(int x) {
    x %= 10;
    if (x < 0)
        x += 10;
    return x;
}

int init(int l, bool formin) {
    for (int i = l; i < l + n; ++i)
        for (int j = i; j < l + n; ++j)
            for (int k = 1; k <= m; ++k)
            if (formin)
                f[i][j][k] = INT_MAX;
            else
                f[i][j][k] = 0;
    for (int i = l; i < l + n; ++i) {
        for (int j = i; j < l + n; ++j)
            f[i][j][1] = mod(sum[j] - sum[i - 1]);
    }
    return 0;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
        data[i + n] = data[i];
    }
    sum[0] = 0;
    for (int i = 1; i <= n * 2; ++i)
        sum[i] = sum[i - 1] + data[i - 1];
    int ans = INT_MAX;
    for (int pin = 0; pin < n; ++pin) {
        init(pin, true);
        for (int k = 2; k <= m; ++k)
            for (int l = k; l <= n; ++l)
                for (int i = pin; i < pin + n - l; ++i) {
                    int j = i + l;
                    for (int x = i; x < j; ++x)
                        for (int xk = 1; xk <= min(x - i + 1, k - 1); ++xk)
                            f[i][j][k] = min(f[i][x][xk] * f[x + 1][j][k - xk], f[i][j][k]);
                }
        ans = min(ans, f[pin][pin + n - 1][m]);
    }
    cout << ans << endl;
    ans = 0;
    for (int pin = 0; pin < n; ++pin) {
        init(pin, false);
        for (int k = 2; k <= m; ++k)
            for (int l = k; l <= n; ++l)
                for (int i = pin; i < pin + n - l; ++i) {
                    int j = i + l;
                    for (int x = i; x < j; ++x)
                        for (int xk = 1; xk <= min(x - i + 1, k - 1); ++xk)
                            f[i][j][k] = max(f[i][x][xk] * f[x + 1][j][k - xk], f[i][j][k]);
                }
        ans = max(ans, f[pin][pin + n - 1][m]);
    }
    cout << ans << endl;
    return 0;
}
