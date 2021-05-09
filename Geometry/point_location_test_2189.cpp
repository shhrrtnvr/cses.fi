#include <bits/stdc++.h>
using namespace std;

typedef long long T;
typedef complex<T> pt;
#define x real()
#define y imag()

T cross(pt v, pt w) { return (conj(v)*w).y; }
T orient(pt a, pt b, pt c) { return cross(b-a, c-a); }


int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        int x1, y1, x2, y2, x3, y3;
        scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
        auto o = orient({x1, y1}, {x2, y2}, {x3, y3});
        if (o == 0) printf("TOUCH\n");
        else if (o > 0) printf("LEFT\n");
        else printf("RIGHT\n");
    }
}