#include <bits/stdc++.h>
using namespace std;
#define SZ 100007

vector<int> AdjList[SZ];
int dist[SZ];
bool visited[SZ];

// returns tuple containing <print_complete?, cycle_found?, distance>
tuple<bool, bool, int> dfs(int u, int d, int p) { 
    visited[u] = true;
    dist[u] = d;
    for (auto v : AdjList[u]) {
        if (v == p) continue;
        if (visited[v]) {
            printf("%d\n%d %d", dist[u]-dist[v]+2, v, u);
            return {false, true, v};
        }
        else {
            auto [t, f, l] = dfs(v, d+1, u);
            if (t) return {t, f, l};
            if (f) {
                printf(" %d", u);
                if (u == l) {
                    t = true;
                    printf("\n");
                }
                return {t, f, l};
            }
        }
    }
    return {false, false, 0};
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        AdjList[u].emplace_back(v);
        AdjList[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]){
            auto [t, f, l] = dfs(i, 0, 0);
            if (f) return 0;    
        }
    }
    printf("IMPOSSIBLE\n");
    return 0;
}