#include <bits/stdc++.h>
using namespace std;
#define MX 1000005

int dp[MX];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        dp[i] = 0x3f3f3f3f;
        int tmp = i;
        while (tmp) {
            int dig = tmp % 10; tmp /= 10;
            if (dig > i) continue;
            dp[i] = min(dp[i], 1+dp[i-dig]);
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}