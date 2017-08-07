#include <iostream>
#define MAXN 15
#define MAXM 15

using namespace std;

int n, m, kx, ky;
int f[MAXN + 1][MAXM + 1];
int unblk[MAXN + 1][MAXM + 1];
int xdir[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int ydir[8] = {2, -2, 2, -2, 1, -1, 1, -1};

int main() {
    cin >> n >> m >> kx >> ky;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j) {
            f[i][j] = 0;
            unblk[i][j] = 1;
        }
    unblk[kx][ky] = 0;
    for (int i = 0; i < 8; ++i) {
        int x = kx + xdir[i];
        int y = ky + ydir[i];
        if ((0 <= x) && (x <= n) && (0 <= y) && (y <= m))
            unblk[x][y] = 0;
    }
    for (int i = 0; i <= n; ++i)
        if (unblk[i][0])
            f[i][0] = 1;
        else
            break;
    for (int i = 0; i <= m; ++i)
        if (unblk[0][i])
            f[0][i] = 1;
        else
            break;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            if (unblk[i][j])
                f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    cout << f[n][m] << endl;
}
