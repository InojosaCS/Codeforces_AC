#include <bits/stdc++.h>
 
using namespace std;

void solve(){
	int r,n;
	cin >> r >> n;
	
	vector<int> t(n+1, 0);
	vector<int> x(n+1, 1);
	vector<int> y(n+1, 1);
	
	for (int i = 1; i <= n; i++)
		cin >> t[i] >> x[i] >> y[i];

	vector<int> dp(n+1, 0);
	vector<int> mx(n+1, -1);
	
	for (int i = 1; i <= n; i++)
	{
		int current = (x[i] + y[i] - 2) <= t[i] ? 0 : -1;
		
		for (int j = i - 1; j >= 0 && j + 1123 >= i; j--)
		{
			if(dp[j] && t[i] - t[j] >= abs(x[i] - x[j]) + abs(y[i] - y[j])){
				current = max(dp[j], current);
			}
		}
		
		dp[i] = current + 1;
		if(i >= 1123) dp[i] = max(dp[i], mx[i-1123] + 1);
		mx[i] = max(dp[i], mx[i-1]);
	}
	
	cout << mx[n] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	int tt = 1;
	//cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}
