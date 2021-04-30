#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int p[n];
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);
    sort(p, p+n);
    int i = 0, j = n-1;
    long long cost = 0;
    while (i < j) cost += p[j--]-p[i++];
    printf("%lld\n", cost);
    return 0;
}