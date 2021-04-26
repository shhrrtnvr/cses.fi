#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    scanf("%d", &n);
    tuple<int, int> t[2*n];
    for (int i = 0, a, b; i < n; i++) {
        scanf("%d %d", &a, &b);
        t[2*i] = {b, -1};
        t[2*i+1] = {a, 1};
    }
    sort(t, t+2*n);
    int cnt = 0, mx = 0;
    for (auto [a, b] : t) {
        cnt += b;
        mx = max(mx, cnt);
    }
    printf("%d\n", mx);
    return 0;
}