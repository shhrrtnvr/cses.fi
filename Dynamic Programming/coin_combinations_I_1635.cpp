#include <bits/stdc++.h>
using namespace std;
#define MX 1000007
#define MOD 1000000007

int coin_count[MX];

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    int coins[n];
    for (int i = 0; i < n; i++) scanf("%d", &coins[i]);
    coin_count[0] = 1;
    for (int i = 0; i < x; i++) {
        for (auto val : coins) {
            if (i+val > x) continue;
            coin_count[i+val] = (coin_count[i+val] + coin_count[i]) % MOD;
        }
    }
    printf("%d\n", coin_count[x]);
    return 0;
}