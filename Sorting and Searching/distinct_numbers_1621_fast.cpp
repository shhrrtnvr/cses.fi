#include<bits/stdc++.h>
using namespace std;

int a[200005];


int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    int cnt = 0;
    for (int i = 1; i <= n; i++) if (a[i] != a[i-1]) cnt++;
    printf("%d\n", cnt);
}