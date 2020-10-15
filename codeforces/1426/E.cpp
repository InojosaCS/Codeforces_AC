#include <bits/stdc++.h>
 
using namespace std;

void solve(){
	int n;
	cin >> n;
	int a1, a2, a3;
	int b1, b2, b3;
	cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
	
	int mx = min(a1, b2) + min(a2, b3) + min(a3, b1);
	int mn = min(b1, a1 + a2) + min(b2, a2 + a3) + min(b3, a3 + a1);
	
	mn = n-mn;
	cout << mn << " " << mx << "\n";
	
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	int tt = 1;
	//cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}
