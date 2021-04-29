#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
 
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    long long dist[n+1];
    memset(dist, INF, sizeof dist);
    dist[1] = 0;
    vector<pair<int, long long> > AdjList[n+1];
    for (int i = 0, a, b, c; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        AdjList[a].emplace_back(make_pair(b, c));
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;
    bool processed[n+1];
    //for (int i = 0; i <= n; i++) processed[i] = false;
    memset(processed, false, sizeof processed);
    dist[1] = 0;
    pq.push(make_pair(0, 1));
    while (!pq.empty()) {
        auto [du, u] = pq.top(); pq.pop();
        if (processed[u]) continue;
        processed[u] = true;
        for (auto [v, c] : AdjList[u]) {
            if (du + c < dist[v]) {
                dist[v] = du + c;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i-1) printf(" ");
        printf("%lld", dist[i]);
    }
    printf("\n");
    return 0;
}
