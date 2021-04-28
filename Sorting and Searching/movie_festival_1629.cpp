#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    tuple<int, int> t[n];
    for (int i = 0; i < n; i++) scanf("%d %d", &get<0>(t[i]), &get<1>(t[i]));
    sort(t, t+n, [](auto a, auto b) {
        return get<1>(a) < get<1>(b);
    });
    int cnt = 0, lastend = -1;
    for (auto [st, en] : t) {
        if (st < lastend) continue;
        cnt++;
        lastend = en;
    }
    printf("%d\n", cnt);
    return 0;
}