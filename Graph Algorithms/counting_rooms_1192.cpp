#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<string> grid;
int dfs(int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '#' || grid[i][j] == 'x') return 0;
    grid[i][j] = 'x';
    for (int x : {-1,1}){
        dfs(i+x, j);
        dfs(i, j+x);
    }
    return 1;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>m;
    grid.assign(n, string());
    for (int i = 0; i < n; i++){
        cin>>grid[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) ans += dfs(i, j);
    }
    cout<<ans<<endl;
}