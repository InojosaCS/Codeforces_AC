#include <bits/stdc++.h>

using namespace std;

void solve() {
    int64_t p, q;
    cin >> p >> q;
    
    if(p % q > 0){
        cout << p << "\n";
        return;
    }
    
    vector<int64_t> divs;
    
    for (int i = 1; i*i <= q; i++)
    {
        if(p % i == 0) divs.push_back(i);
        if(p % i == 0) divs.push_back(q/i);
    }
    
    int64_t ans = 1;
    
    for(int d : divs){
        int64_t x = p / d;
        //cout << x << "\n";
        //int t = 3;
        while(d > 1 && x && x % q == 0 && x % d == 0) x = x / d;
        if(p % x == 0 && x % q > 0) ans = max(ans, x);
    }
    
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int32_t tt = 1;
    cin >> tt;

    while(tt-->0) solve();

    return 0;
}
