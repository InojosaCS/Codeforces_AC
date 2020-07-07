#include<bits/stdc++.h>

using namespace std;

int main(){

	int n,m,k;
	cin >> n >> m >> k;
	vector<vector<long long> > dp(k+1, vector<long long>(n+1, 0ll));
	vector<long long> pre(n+1,0ll), a(n+1,0ll);
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i+1];
		pre[i+1] = a[i+1]+pre[i];
	}
	
	long long prev = 0ll;
	for (int i = 1; i <= k; i++)
	{
		prev = 0ll;
		for(int j = i*m; j <= n; j++){
			dp[i][j] = max(prev, dp[i-1][j-m] + pre[j] - pre[j-m]);
			prev = dp[i][j];
			//cout << prev << " ";
		}
		//cout << "\n";
	}
	cout << prev << "\n";
	return 0;
	
	
 }
