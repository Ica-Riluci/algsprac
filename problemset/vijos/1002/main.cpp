#include <iostream>
#include <memory.h>
#define MAXM 100

using namespace std;

int l, s, t, m;
int stone[MAXM * 2];

int delta(int p) {
    int l = 1, r = m;
    while (l < r) {
        int mid = (l + r) / 2;
        if (stone[mid] >= p) { r = mid; }
        else { l = mid + 1; }
    }
    if (stone[l] == p) { return 1; }
    return 0;
}

int min(int a, int b) {
    if (a < b) { return a; }
    return b;
}

int main() {
    cin >> l >> s >> t >> m;
    stone[0] = 0;
    for (int i = 0; i < m; ++i) {
        int j = i, tmp;
        cin >> tmp;
        while (j > 0) {
            if (stone[j] > tmp) { stone[j + 1] = stone[j]; }
            else break;
            --j;
        }
        stone[j + 1] = tmp;
    }
    if (s == t) {
        int ans = 0;
        for (int i = 0; i < m; ++i) { ans += (stone[i + 1] % s == 0); }
        cout << ans << endl;
        return 0;
    }
    int rmfac = t * (t - 1);
    int delfac = 0;
    for (int i = 1; i <= m; ++i) {
        stone[i] -= delfac;
        int x = stone[i] - stone[i - 1];
        if (x > rmfac) {
            delfac += x - rmfac;
            stone[i] = stone[i - 1] + rmfac;
        }
    }
    int *f = new int[stone[m] + t * 2];
    for (int i = 0; i < stone[m] + t * 2; ++i) { f[i] = 200; }
    f[0] = 0;
    for (int i = 0; i <= stone[m]; ++i) {
        for (int j = s; j <= t; ++j) {
            f[i + j] = min(f[i + j], f[i] + delta(i + j));
        }
    }
    int ans = f[stone[m]];
    for (int i = 1; i < t; ++i) { ans = min(ans, f[stone[m] + i]); }
    cout << ans << endl;
    return 0;
}
