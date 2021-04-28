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
    sort(a.begin(), a.end(), [](auto a, auto b) {return get<0>(a) < get<0>(b);});
    for (int i = 0; i < n-1; i++) {
        int target = sum - get<0>(a[i]);
        int j = i+1, k = n-1;
        while (j <= k) {
            int m = j + (k-j) / 2;
            if (get<0>(a[m]) < target) j = m+1;
            else k = m-1;
        }

        if (get<0>(a[i])+get<0>(a[j]) == sum) {
            printf("%d %d\n", get<1>(a[i]), get<1>(a[j]));
            return 0;
        }
    }
    printf("IMPOSSIBLE\n");
    return 0;
}