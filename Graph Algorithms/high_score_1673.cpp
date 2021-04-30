#include <bits/stdc++.h>
using namespace std;
#define INF  0x3f3f3f3f

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    long long dist[n+1]; 
    memset(dist, -INF, sizeof dist);
    const long long LLINF = -dist[0]; 
    dist[1] = 0;
    tuple<int, int, long long> EdgeList[m];
    for (auto &e : EdgeList) scanf("%d %d %lld", &get<0>(e), &get<1>(e), &get<2>(e));

    for (int i = 1; i < n; i++) {
        for (auto [u, v, w] : EdgeList) {
            if (dist[u] == dist[0]) continue;   //dist[0] = -LLINF and correct implementation requires to skip these cases and continue
            dist[v] = max(dist[v], dist[u] + w);  //its also important to limit to max value to avoid possible overflow
        }
    }

    for (int i = 1; i < n; i++) {
        for (auto [u, v, w] : EdgeList) {
            if (dist[u] == dist[0]) continue;
            if (dist[u] + w > dist[v])
                dist[v] = LLINF;    //marks as path contains positive cycle
        }
    }

    printf("%lld\n", dist[n] == LLINF ? -1 : dist[n]);
    return 0;
}