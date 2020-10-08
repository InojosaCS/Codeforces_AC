#include <bits/stdc++.h>
 
using namespace std;

void solve(){
	int n, a;
	cin >> n;
	vector<vector<int>> g(n+1, {0});
	
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		g[a].push_back(i+1);
	}
	
	vector<int> ans(n+2,1e9);
	
	for (int i = 0; i <= n; i++)
	{
		int mx = 0;
		g[i].push_back(n+1);
		
		for(int x = 0; x + 1 < (int) g[i].size(); x++)
			mx = max(mx, g[i][x+1] - g[i][x]);

		ans[mx] = min(i, ans[mx]);
	}
	
	ans[0] = 1e9;
	
	for (int i = 1; i <= n; i++)
	{
		ans[i] = min(ans[i], ans[i-1]);
		if(ans[i] == 1e9) cout << "-1 ";
		else cout << ans[i] << " ";
	}
	
	cout << "\n";
	return;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	int tt = 1;
	cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}
