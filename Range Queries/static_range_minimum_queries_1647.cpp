#include<bits/stdc++.h>
using namespace std;
#define MX 200005
int a[MX];
int st[MX][26]; 
int lg[MX];
int lg2(int n) {
    if (n==1) return 0;
    if (lg[n] == 0) return lg[n] = 1+lg2(n>>1);
    return lg[n];
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) st[i][0] = a[i];
    int k = lg2(n);
    for (int j = 1; j <= k; j++) 
        for (int i = 0; i + (1 << j) <= n; i++) 
            st[i][j] = min(st[i][j-1], st[i + (1<<(j-1))][j-1]);

    for (int i = 0, l, r; i < q; i++) {
        scanf("%d %d", &l, &r); l--,r--;
        int j = lg2(r-l+1);
        int mn = min(st[l][j], st[r - (1 << j) + 1][j]);
        printf("%d\n", mn);
    }
    return 0;
}