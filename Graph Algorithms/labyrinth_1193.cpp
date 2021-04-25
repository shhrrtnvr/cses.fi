#include<bits/stdc++.h>
using namespace std;
const tuple<int, int, char> moves[] = {{0, 1, 'R'}, {0, -1, 'L'}, {1, 0, 'D'}, {-1, 0, 'U'}};

vector<string> grid;
int n, m;
string direction;

bool search(tuple<int, int> startpos, tuple<int, int> endpos) {
    auto [i, j] = startpos;
    auto [ei, ej] = endpos;
    grid[i][j] = '#';
    grid[ei][ej] = '.';
    tuple<int, int, char> trace[n][m];
    trace[i][j] = {i, j, '\0'};
    
    queue<tuple<int, int> > q;
    q.push({i, j});
    
    bool found = false;
    while (!(q.empty() || found)) {
        auto [ui, uj] = q.front(); q.pop();
        for (auto [x, y, d] : moves) {
            x += ui; y+= uj;
            if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != '.') continue;
            grid[x][y] = '#';
            trace[x][y] = {ui, uj, d};
            q.push({x, y});
            if (x == ei && y == ej) {found = true; break;}
        }
    }
    if (found) {
        auto [i, j, d] = trace[ei][ej];
        while (i != ei || j != ej) {
            direction += d;
            tie(ei, ej) = {i, j};
            tie(i, j, d) = trace[i][j];
        }
        reverse(begin(direction), end(direction));
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    grid.assign(n, string());
    tuple<int, int> startpos, endpos;
    for (int i = 0; i < n; i++) {
        cin>>grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') startpos = {i, j};
            else if (grid[i][j] == 'B') endpos = {i, j};
        }
    }
    bool possible = search(startpos, endpos);
    if (possible) 
        cout<<"YES"<<endl<<direction.size()<<endl<<direction<<endl;
    else 
        cout<<"NO"<<endl;
    return 0;
}