#include <bits/stdc++.h>
using namespace std;

inline int input(){
	int t = 0;
	char c;
	while((c=getchar_unlocked())!='\n'&&c!=' '&&c!=EOF)t=t*10+c-48;
	return t;
}
int main() {
    int n = input();
    tuple<int, int> t[n<<1];
    for (int i = 0, j = 0; i < n; i++) {
        t[j++] = {input(), 1};
        t[j++] = {input(), -1};
    }
    sort(t, t+2*n);
    int cnt = 0, mx = 0;
    for (auto [a, b] : t) mx = max(mx, cnt+=b);
    puts(to_string(mx).c_str());
    return 0;
}