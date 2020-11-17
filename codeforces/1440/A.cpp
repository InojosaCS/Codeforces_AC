#include <bits/stdc++.h>
 
using namespace std;

#define int int64_t

void solve(){
    int64_t n, c0, c1, h;
    cin >> n >> c0 >> c1 >> h;
    
    string s;
    cin >> s;
    int64_t cnt1 = 0;
    
    for (int i = 0; i < n; i++)
    {
	cnt1 += s[i] - '0';
    }
    
    int64_t cnt2 = n - cnt1, ans = 1e18;
    
    for (int i = 0; i < n+1; i++)
    {
	//if(i > cnt1) ans = min(ans, (i-cnt1) * c1 + (n - i) * c0);
	//else ans = min(ans, (cnt1-i) * c1 + (n - i) * c0);
	ans = min(ans, (abs(i-cnt1) * h + c1 * i + c0 * (n-i)));
    }
    
    cout << ans << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int32_t tt = 1;
    cin >> tt;

    while(tt-->0) solve();
    
    return 0;
}	
