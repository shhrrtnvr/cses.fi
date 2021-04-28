#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sum;
    scanf("%d %d", &n, &sum);
    vector<tuple<int, int> > a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &get<0>(a[i]));
        get<1>(a[i]) = i+1;
    }
    sort(begin(a), end(a), [](auto a, auto b) { return get<0>(a) < get<0>(b); });
    int i = 0, j = n-1;
    while (i < j) {
        int temp = get<0>(a[i]) + get<0>(a[j]);
        if (temp == sum) {
            printf("%d %d\n", get<1>(a[i]), get<1>(a[j]));
            return 0;
        }
        if (temp < sum) i++;
        else j--;
    }
    printf("IMPOSSIBLE\n");
    return 0;
}