#include <bits/stdc++.h>
using namespace std;
#define SZ 200007

int price[SZ], p[SZ];
int find(int n) {
    return (n==p[n]) ? n : (p[n] = find(p[n]));
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; i++) p[i] = i;
    for (int i = 0; i < n; i++) scanf("%d", &price[i]);
    sort(price, price+n);
    for (int i = 0, dummy; i < m; i++) {
         scanf("%d", &dummy);
        int idx = upper_bound(price, price+n, dummy) - price;
        int pos = find(idx);
        if (pos == 0) printf("-1\n");
        else {
            printf("%d\n", price[pos-1]);
            p[pos]--;
        }
    }
    return 0;
}