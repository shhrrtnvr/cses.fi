#include <bits/stdc++.h>
using namespace std;

void trace_path(tuple<bool, int, int> *state, int u) {
    if (u == 0) { printf("1"); return; }
    trace_path(state, get<1>(state[u]));
    printf(" %d", u+1);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> AdjList[n];
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v); 
        AdjList[u-1].emplace_back(v-1);
        AdjList[v-1].emplace_back(u-1);
    }
    queue<int> q;
    tuple<bool, int, int> state[n];
    state[0] = {true, -1, 1};
    q.push(0); 
    while (!q.empty() && !get<0>(state[n-1])) {
        auto u = q.front(); q.pop();
        for (auto v : AdjList[u]) {
            if (get<0>(state[v])) continue;
            state[v] = {true, u, get<2>(state[u])+1};
            q.push(v);
        }
    }
    if (!get<0>(state[n-1])) printf("IMPOSSIBLE\n");
    else {
        printf("%d\n", get<2>(state[n-1]));
        trace_path(state, n-1);
        printf("\n");
    }
    return 0;
}