#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int main() {
    int n;
    scanf("%d", &n);
    long long mx = -INF, sum = 0;
    for (long long i = 0, dummy; i < n; i++) {
        scanf("%lld", &dummy);
        sum = max(dummy, sum+dummy);
        mx = max(sum, mx);
    }
    printf("%lld\n", mx);
    return 0;
}