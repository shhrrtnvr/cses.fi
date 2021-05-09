#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    long long fx, fy;
    scanf("%lld %lld", &fx, &fy);
    long long x1 = fx, y1 = fy, x2, y2;
    long long area = 0;
    for (int i = 1; i < n; i++) {
        scanf("%lld %lld", &x2, &y2);
        area += (x1 * y2 - x2 * y1);
        x1 = x2, y1 = y2;
    }
    area += (x1 * fy - y1 * fx);
    printf("%lld\n", abs(area));
}