#include <iostream>
#include <string>
#include <algorithm>
#define MAXN 50

using namespace std;

int n = 0;
int data[MAXN], f[MAXN];

int num(string s) {
    int a = 0;
    int exp = 1;
    for (int i = s.length() - 1; i >= 0; --i) {
        a += exp * (s[i] - '0');
        exp *= 10;
    }
    return a;
}

int main() {
    string s;
    string tmp = "";
    cin >> s;
    s += ',';
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ',') {
            ++n;
            data[n - 1] = num(tmp);
            tmp = "";
        }
        else
            tmp += s[i];
    }
    for (int i = 0; i < n; ++i)
        f[i] = 1;
    for (int i = 1; i < n; ++i)
        for (int j = i - 1; j >= 0; --j)
            if (data[i] <= data[j])
                f[i] = max(f[i], f[j] + 1);
    int ans = 1;
    for (int i = 0; i < n; ++i)
        ans = max(f[i], ans);
    cout << ans << ',';
    for (int i = 0; i < n; ++i)
        f[i] = 1;
    for (int i = 1; i < n; ++i)
        for (int j = i - 1; j >= 0; --j)
            if (data[i] > data[j])
                f[i] = max(f[i], f[j] + 1);
    ans = 1;
    for (int i = 0; i < n; ++i)
        ans = max(f[i], ans);
    cout << ans - 1 << endl;
    return 0;
}
