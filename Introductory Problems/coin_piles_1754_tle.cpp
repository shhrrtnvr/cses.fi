#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b;
    scanf("%d %d", &a, &b);
    while (a > 0 && b > 0) {
        if (a >= b) a -= 2, b--;
        else a--, b -= 2;
    }
    printf("%s\n", (a == 0 && b == 0) ? "YES" : "NO");
}

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) solve();
    return 0;
}