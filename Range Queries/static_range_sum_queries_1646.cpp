#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    long long psum[n+1];
    psum[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &psum[i]);
        psum[i] += psum[i-1];
    }
    for (int i = 0, a, b; i < q; i++) {
        scanf("%d %d", &a, &b);
        printf("%lld\n", psum[b]-psum[a-1]);
    }
    return 0;
}