#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define MX 200005

int n, st[MX*2];

void update(int i, int v) {
    i += n;
    st[i] = v;
    for (i>>=1; i >= 1; i>>=1) st[i] = min(st[i<<1], st[(i<<1)+1]);
}
int query(int l, int r){
    int ans = INF;
    for (l+=n, r+=n; l <= r; l>>=1, r>>=1) {
        if (l & 1) ans = min(ans, st[l++]);
        if (!(r&1)) ans = min(ans, st[r--]);
    }
    return ans;
}

int main() {
    int q;
    scanf("%d %d", &n, &q);
    //inputs in the array directly into st[n..2n)
    for(int i = 0; i < n; i++) scanf("%d", &st[i+n]);
    //builds segment tree in st[1..n)
    for (int i = n-1; i > 0; i--) st[i] = min(st[i<<1], st[(i<<1) + 1]);

    for (int i = 0; i < q; i++) {
        int op;
        scanf("%d", &op);
        switch(op) {
            case 1:
                int k, u;
                scanf("%d %d", &k, &u);
                update(k-1, u);
                break;
            case 2:
                int a, b;
                scanf("%d %d", &a, &b);
                printf("%d\n", query(a-1, b-1));
                break;
        }
    }
}