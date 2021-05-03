#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    int pr[n], pg[n];
    for (auto &v : pr) scanf("%d", &v);
    for (auto &v : pg) scanf("%d", &v);
    int dp[x+1];
    memset(dp, 0, sizeof dp);
    for (int j = 0; j < n; j++) {
        for (int i = x; i > 0; i--) {
            if (i-pr[j] < 0) continue;
            dp[i] = max(dp[i], dp[i-pr[j]] + pg[j]);
        }
    }
    printf("%d\n", dp[x]);
    return 0;
}