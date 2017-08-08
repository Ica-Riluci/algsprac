#include <iostream>
#include <memory>
#include <algorithm>
#define MAXN 120

using namespace std;

int n;
int mbr[MAXN];
int lis[MAXN], lis_r[MAXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> mbr[i];
    for (int i = 0; i < n; ++i)
        lis[i] = lis_r[i] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if ((mbr[i] > mbr[j]) && (lis[i] < lis[j] + 1))
                lis[i] = lis[j] + 1;
            if ((mbr[n - i - 1] > mbr[n - j - 1]) && (lis_r[n - i - 1] < lis_r[n - j - 1] + 1))
                lis_r[n - i - 1] = lis_r[n - j - 1] + 1;
        }
    }
    int ans = 1;
    for (int i = 0; i < n; ++i)
        ans = max(ans, lis[i] + lis_r[i] - 1);
    cout << n - ans << endl;
    return 0;
}
