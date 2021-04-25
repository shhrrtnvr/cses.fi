#include <bits/stdc++.h>
using namespace std;
int n, m, c;
vector<int> p;
int find(int i) {
    return (p[i] == i) ? i : p[i] = find(p[i]);
}
void join(int i, int j) {
    i = find(i), j = find(j);
    if (i != j) p[i] = j, c--;
}

int main() {
    scanf("%d %d", &n, &m); c = n;
    p.reserve(n+1);
    for (int i = 1; i <= n; i++) p[i] = i;
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        join(u, v);
    }
    int dj[c];
    int k=0;
    for (int i = 1; i <= n; i++) if (p[i] == i) dj[k++] = i;
    
    printf("%d\n", c-1);
    for (int i = 1; i < c; i++) printf("%d %d\n", dj[i-1], dj[i]);
    return 0;
}