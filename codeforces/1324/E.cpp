#include <bits/stdc++.h>
 
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (__int64) x.size()
#define debug(x) cout << (#x) << " is " << x << "\n";

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.precision(20);

	int n,h,l,r;
	cin >> n >> h >> l >> r;
	vector<vector<int>> dp(n+1, vector<int>(h,0));
	vector<vector<bool>> visited(n+1, vector<bool>(h,false));
	vector<int> a(n);
	visited[0][0] = true;
	
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < h; ++j)
		{
			if(visited[i][j]){
				int x = ((l<=((j+a[i])%h)) && (((j+a[i])%h)<=r)) ? (dp[i][j]+1) : dp[i][j];
				int b = ((l<=((j+a[i]-1)%h)) && (((j+a[i]-1)%h)<=r)) ? (dp[i][j]+1) : dp[i][j];
				dp[i+1][(j+a[i])%h] = max(x, dp[i+1][(j+a[i])%h]);
				dp[i+1][(j+a[i]-1)%h] =  max(b, dp[i+1][(j+a[i]-1)%h]);
				visited[i+1][(j+a[i]-1)%h] = true;
				visited[i+1][(j+a[i])%h] = true;
			}
		}
	}

	int mx = 0;
	
	for (int i = 0; i < h; ++i)
		mx = max(mx, dp[n][i]);	
	
	cout << mx << "\n";
	return 0;
}
