#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a+n);
    int i = 0, j = n-1, cnt = 0;
    while (i <= j) {
        if (a[j] > x) j--;
        else if (a[i] + a[j] > x) cnt++, j--;
        else i++, j--, cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}