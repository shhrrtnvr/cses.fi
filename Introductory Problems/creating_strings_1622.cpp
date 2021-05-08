#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    return n==0?1:n*fact(n-1);
}

int cnt[26];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string s;
    cin>>s;
    sort(s.begin(), s.end());
    for (auto c : s) cnt[c-'a']++;
    int ans = fact(s.size());
    for (int i = 0; i < 26; i++) ans /= fact(cnt[i]);
    cout<<ans<<'\n';
    do {
        cout<<s<<'\n';
    } while (next_permutation(s.begin(), s.end()));
}