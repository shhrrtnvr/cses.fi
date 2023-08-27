#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    long long missing = 1LL;
    for (int i = 0; i < n; i++) {
        if (a[i] > missing ) break;
        missing += a[i];
    }
    printf("%lld\n", missing);
    return 0;
}

