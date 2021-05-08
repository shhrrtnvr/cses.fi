#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int pre[n+1]; pre[0] = 0;
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        pre[i] = x^pre[i-1];
    }
    for (int i = 0, a, b; i < q; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", pre[b] ^ pre[a-1]);
    }
}