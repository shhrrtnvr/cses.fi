#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
 
int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    int coin_val[n];
    for (int i = 0; i < n; i++) scanf("%d", &coin_val[i]);
    int min_coins[x+1];
    memset(min_coins, INF, sizeof min_coins);
    min_coins[0] = 0;
    for (int i = 0; i < x; i++) {
        for (auto val : coin_val) {
            if (i+val > x) continue;
            min_coins[i+val] = min(min_coins[i+val], min_coins[i]+1);
        }
    }
    printf("%d\n", min_coins[x] == INF ? -1 : min_coins[x]);
    return 0;
}