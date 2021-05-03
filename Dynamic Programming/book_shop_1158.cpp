#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    int price[n], page[n];
    for (auto &v : price) scanf("%d", &v);
    for (auto &v : page) scanf("%d", &v);
    int dp[x+1];
    memset(dp, 0, sizeof dp);
    for (int j = 0; j < n; j++) {
        for (int i = x; i > 0; i--) {
            if (i-price[j] < 0) continue;
            dp[i] = max(dp[i], dp[i-price[j]] + page[j]);
        }
    }
    priceintf("%d\n", dp[x]);
    return 0;
}