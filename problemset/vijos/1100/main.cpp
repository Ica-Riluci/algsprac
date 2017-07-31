#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int *data = new int[n];
    int *f = new int[n * n];
    int *root = new int[n * n];
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
        f[i * (n + 1)] = data[i];
        root[i * (n + 1)] = i;
    }
    for (int k = 1; k < n; ++k) {
        for (int l = 0; l < n - k; ++l) {
            int r = l + k;
            for (int i = l; i <= r; ++i) {
                int lpts = (i > l) ? f[l * n + i - 1] : 1, rpts = (i < r) ? f[(i + 1) * n + r] : 1;
                int v = lpts * rpts + data[i];
                if (v > f[l * n + r]) {
                    f[l * n + r] = v;
                    root[l * n + r] = i;
                }
            }
        }
    }
    cout << f[n - 1] << endl;
    int *stack = new int[n * 2];
    int *tree = new int[n + 1];
    int ptr = 0;
    stack[0] = 0;
    stack[n] = n - 1;
    tree[0] = 0;
    while (ptr > -1) {
        int l = stack[ptr], r = stack[ptr + n];
        tree[++tree[0]] = root[l * n + r];
        --ptr;
        if (r > root[l * n + r]) {
            ++ptr;
            stack[ptr] = root[l * n + r] + 1;
            stack[ptr + n] = r;
        }
        if (l < root[l * n + r]) {
            ++ptr;
            stack[ptr] = l;
            stack[ptr + n] = root[l * n + r] - 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (i > 1)
            cout << ' ';
        cout << tree[i] + 1;
    }
    cout << endl;
    return 0;
}
