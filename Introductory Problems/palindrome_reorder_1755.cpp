#include <bits/stdc++.h>
using namespace std;

int cnt[26];

int main() {
    char ch;
    int tot = 0;
    while ((ch = getchar()) != '\n') cnt[ch-'A']++, tot++;
    int odd = 0;
    for (auto c : cnt) odd += (c%2);
    if (odd > 1) {
        printf("NO SOLUTION\n");
        return 0;
    }
    char ans[tot+1];
    ans[tot] = '\0';
    int j = 0, k = tot-1;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2) ans[tot/2] = 'A'+i;
        cnt[i] /= 2;
        while (cnt[i]--)
            ans[j++] = ans[k--] = 'A'+i;
    }
    printf("%s\n", ans);
}