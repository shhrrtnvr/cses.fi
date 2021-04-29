#include<bits/stdc++.h>
using namespace std;
#define SZ 1000009
#define MOD 1000000007

int dp[SZ];

int main() {
    int n;
    scanf("%d", &n);
    dp[0] = 1;
    for (int i = 0; i < n; i++) 
        for (int j = 1; j <= 6; j++)
            dp[i+j] = (dp[i] + dp[i+j]) % MOD;
    printf("%d\n", dp[n]);
    return 0;
}