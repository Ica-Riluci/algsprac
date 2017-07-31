#include <iostream>

using namespace std;

int data[10];
int h, ans = 0;

int main() {
    for (int i = 0; i < 10; ++i) cin >> data[i];
    cin >> h;
    for (int i = 0; i < 10; ++i)
        if (data[i] <= h + 30)
            ++ans;
    cout << ans << endl;
    return 0;
}
