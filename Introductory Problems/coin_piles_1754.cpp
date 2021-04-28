#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int a, b;
    scanf("%d %d", &a, &b); 
    if (max(a, b) > 2*min(a, b)) return false;
    return (a+b) % 3 == 0;
}


int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        if (solve()) printf("YES\n");
        else printf("NO\n");
    }
}