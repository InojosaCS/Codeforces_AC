#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin >> n;
	int ans = 4*n;
	
	for (int i = 0; i < n; i++)
	{
		cout << ans - 2*i << " ";
	}
	cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int32_t tt = 1;
	cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}	
