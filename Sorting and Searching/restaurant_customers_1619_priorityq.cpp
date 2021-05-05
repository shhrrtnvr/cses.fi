#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    tuple<int, int> stay[n];
    for (auto &p : stay) scanf("%d %d", &get<0>(p), &get<1>(p));
    sort(stay, stay+n, [](tuple<int, int> a, tuple<int, int> b) { return get<0>(a) < get<0>(b);});

    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(get<1>(stay[0]));
    for (int i = 1; i < n; i++ ) {
        if (pq.top() <= get<0>(stay[i])) pq.pop();
        pq.push(get<1>(stay[i]));
    }
    printf("%d\n", pq.size());
    return 0;
}