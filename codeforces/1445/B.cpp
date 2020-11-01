#include <bits/stdc++.h>

using namespace std;

void solve() {
    int64_t a,b,c,d;
    cin >> a >> b>> c >> d;
    cout << max(a+b, c+d) << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int32_t tt = 1;
    cin >> tt;

    while(tt-->0) solve();

    return 0;
}
