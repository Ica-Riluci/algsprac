#include <iostream>
#define MAXV 25000
#define MAXN 30

using namespace std;

int f[MAXV];
int cargo[MAXN];
int v, n;

int main() {
    cin >> v >> n;
    for (int i = 0; i < n; ++i)
        cin >> cargo[i];
    int vol = 0;
    for (int i = 1; i <= v; ++i)
        f[i] = 0;
    f[0] = 1;
    for (int i = 0; i < n; ++i) {
        int tmpv = vol;
        for (int j = vol; j >= 0; --j)
            if ((f[j]) && (j + cargo[i] <= v)) {
                f[j + cargo[i]] = 1;
                if (j + cargo[i] > tmpv)
                    tmpv = j + cargo[i];
            }
        vol = tmpv;
    }
    cout << v - vol << endl;
    return 0;
}
