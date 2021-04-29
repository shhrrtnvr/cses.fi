#include <bits/stdc++.h>
using namespace std;
#define MX 1000007
#define MOD 1000000007

int ways_count[MX];

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    int coins[n];
    for (int i = 0; i < n; i++) scanf("%d", &coins[i]);
    ways_count[0] = 1;
    for (int i = 0; i < x; i++) {
        for (auto val : coins) {
            if (i+val > x) continue;
            ways_count[i+val] = (ways_count[i+val] + ways_count[i]) % MOD;
        }
    }
    printf("%d\n", ways_count[x]);
    return 0;
}