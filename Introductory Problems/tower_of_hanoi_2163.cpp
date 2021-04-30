#include <bits/stdc++.h>
using namespace std;

void toh(int n, int from, int im, int to) {
    if (n == 0) return;
    toh(n-1, from, to, im);
    printf("%d %d\n", from, to);
    toh(n-1, im, from, to);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", (1<<n) -1);
    toh(n, 1, 2, 3);
    return 0;
}