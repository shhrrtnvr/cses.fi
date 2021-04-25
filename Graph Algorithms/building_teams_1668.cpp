#include <bits/stdc++.h>
using namespace std;
#define SZ 100007

int n, m;
vector<int> AdjList[SZ];
int color[SZ];
bool visited[SZ];

bool dfs(int u, int c) {
    bool flag = true;
    visited[u] = true;
    color[u] = c;
    for (auto v : AdjList[u]) {
        if (!visited[v]) flag &= dfs(v, c^1);
        else flag &= (color[v] != c);
        if (!flag) break;
    }
    return flag;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        AdjList[u].emplace_back(v);
        AdjList[v].emplace_back(u);
    }
    
    bool possible = true;
    for (int i = 1; i <= n && possible; i++) 
        if (!visited[i]) possible &= dfs(i, 0);

    if (!possible) printf("IMPOSSIBLE\n");
    else {
        for (int i = 1; i <= n; i++) {
            if (i == 1) printf("%d", color[i]+1);
            else printf(" %d", color[i]+1);
        }
        printf("\n");
    }
}