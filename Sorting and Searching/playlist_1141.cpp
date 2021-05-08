#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> bag;
    queue<int> q;
    int n;
    scanf("%d", &n);
    int mx = 0;
    for (int i = 0, v; i < n; i++) {
        scanf("%d", &v);
        if (bag.count(v) == 1) {
            while (q.front() != v){
                bag.erase(q.front());
                q.pop();
            }
            q.pop();
        }
        bag.insert(v);
        q.push(v);
        if (bag.size() > mx) mx = bag.size();
    }
    printf("%d\n", mx);
}