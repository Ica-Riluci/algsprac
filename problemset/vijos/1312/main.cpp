#define MAXN 400
#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int n;
int data[MAXN][2];
int f[MAXN][MAXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> data[i][0];
        data[i + n][0] = data[i][0];
        data[(i + n - 1) % n][1] = data[i][0];
        data[(i + n - 1) % n + n][1] = data[i][0];
    }
    memset(f, 0, sizeof(f));
    int ans = 0;
    for (int pin = 0; pin < n; ++pin) {
        for (int len = 2; len <= n; ++len)
            for (int i = pin; i <= pin + n - len; ++i) {
                int j = i + len - 1;
                for (int k = i; k < j; ++k)
                    f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + data[i][0] * data[k][1] * data[j][1]);
                }
        ans = max(ans, f[pin][pin + n - 1]);
    }
    cout << ans << endl;
    return 0;
}
