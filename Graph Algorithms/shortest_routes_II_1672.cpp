#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    
    long long dist[n][n];
    for (int i = 0; i < n; i++){
        memset(dist[i], INF, sizeof dist[i]);
        dist[i][i] = 0;
    }
    long long c;
    for (int i = 0, a, b; i < m; i++) {
        scanf("%d %d %lld", &a, &b, &c); a--; b--;
        dist[a][b] = min(dist[a][b], c);    // contains more than 1 road between pairs, thats why min is used
        dist[b][a] = min(dist[a][b], c);
    }
    for (int k = 0; k < n; k++) 
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                
    long long LLINF[1]; 
    memset(LLINF, INF, sizeof LLINF);
    for (int i = 0, a, b; i < q; i++) {
        scanf("%d %d", &a, &b); a--, b--;
        printf("%lld\n", dist[a][b] == LLINF[0] ? -1 : dist[a][b]);
    }
}