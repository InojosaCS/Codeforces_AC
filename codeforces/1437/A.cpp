#include <bits/stdc++.h>

using namespace std;

void solve(){
	int l,r;
	cin >> l >> r;
	int helper = l/2 + l%2==0;
	bool what = helper <= l*2 && helper <= r*2;
	if(l*2 >= r+1) cout << "YES\n";
	else cout << "NO\n";	
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	int32_t tt = 1;
	cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}
