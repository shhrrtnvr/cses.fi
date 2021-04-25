#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int a[n], b[m];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
    sort(a, a+n);
    sort(b, b+m);
    int cnt = 0, i = 0, j = 0;
    while (i != n && j != m) {
        if (b[j]-k > a[i]) i++;
        else if (b[j]+k < a[i]) j++;
        else cnt++, i++, j++;
    }
    printf("%d\n", cnt);
}