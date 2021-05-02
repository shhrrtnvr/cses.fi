#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
    int n;
    scanf("%d", &n);
    char grid[n+1][n+2];
    for (int i = 1; i <= n; i++) scanf("%s", grid[i]+1);
    int dp[n+1][n+1];
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    dp[0][1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (grid[i][j] == '*') dp[i][j] = 0;
            else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }

    printf("%d\n", dp[n][n]);
    return 0;
}