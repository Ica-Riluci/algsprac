#define MAXN 300
#define MAXM 20
#include<cstdio>
#include<iostream>

using namespace std;

int n, m;
int data[MAXN];
int sum[MAXN];
int f1[MAXN][MAXM];
int f2[MAXN][MAXM];

int mod(int a){
    a %= 10;
    if (a < 0) return (10 + a) % 10;
    return a % 10;
}

int main(){
    int ans = 0;
    int ans2 = 0x3f3f3f3f;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> data[i];
        data[i + n] = data[i];
    }
    sum[0] = 0;
    for (int i = 1; i <= 2 * n; i++) sum[i] += sum[i - 1] + data[i];
    for (int s = 0; s < n; s++){
        for (int i = 0; i < MAXN; i++)
            for (int j = 0; j < MAXM; j++) {
                if (i == 0 || j == 0) f1[i][j] = 1, f2[i][j] = 1;
                else f1[i][j] = -0x3f3f3f3f, f2[i][j] = 0x3f3f3f3f;
            }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= min(i, m); j++)
            {
                if (j == 1)
                {
                    f1[i][j] = f2[i][j] = mod(sum[s + i] - sum[s]);
                    continue;
                }
                for (int k = 1; k <= i - j + 1; k++){
                    f1[i][j] = max(f1[i][j], f1[i - k][j - 1] * mod(sum[s + i] - sum[s + i - k]));
                    f2[i][j] = min(f2[i][j], f2[i - k][j - 1] * mod(sum[s + i] - sum[s + i - k]));
                }
            }
        ans = max(ans, f1[n][m]);
        ans2 = min(ans2, f2[n][m]);
    }
    cout << ans2 << endl << ans << endl;
}
