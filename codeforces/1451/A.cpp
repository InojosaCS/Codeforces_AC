#include <bits/stdc++.h> 
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")

using namespace std; 

void solve(){
    int64_t  p;
    cin >> p;
    
    int ans;
    if(p == 1) ans = 0;
    else if(p == 2) ans = 1;
    else if(p % 2 == 0 || p == 3) ans = 2;
    else ans = 3;
    
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
