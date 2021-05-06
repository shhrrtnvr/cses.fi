#include <bits/stdc++.h>
using namespace std;
#define MX 200005
int n;
long long bit[MX];
void add(int i, int delta) {
    for (; i < n; i |= (i+1)) bit[i] += delta;
}
long long query(int i) {
    return i < 0 ? 0LL : bit[i] + query((i&(i+1))-1);
}

int main() {
    int q;
    scanf("%d %d", &n, &q);
    long long a[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        add(i, a[i]);
    }
    for (int i = 0, op, k, u; i < q; i++) {
        scanf("%d %d %d", &op, &k, &u);
        k--;
        switch(op) {
            case 1:
                add(k, u-a[k]);
                a[k] = u;
                break;
            case 2:
                printf("%lld\n", query(u-1) - query(k-1));
                break;
        }
    }
    return 0;
}