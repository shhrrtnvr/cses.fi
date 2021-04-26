#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    multiset<int> price;
    for (int i = 0, p; i < n; i++) {
        scanf("%d", &p);
        price.insert(-p);
    }
    for (int i = 0, p; i < m; i++) {
        if (i) printf(" ");
        scanf("%d", &p);
        auto it = price.lower_bound(-p);
        if (it == price.end()) printf("-1");
        else {
            printf("%d", -*it);
            price.erase(it);
        }
    }
    return 0;
}