#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);

	ll n,m;
	cin >> n >> m;
	ll dp[m+1][n+1], back[m+1][n+1];
	const ll M = 1e9+7;
	
	for(int i=0; i<m+1; i++)
		for(int j=0; j<n+1; j++)
			back[i][j] = dp[i][j] = 0ll;
			
	back[0][n] = dp[0][0] = 1ll;
	// dp[pos][val]
	
	for (int i = 1; i < m+1; i++)
	{
		for (int j = 1; j < n+1; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[i][j] = (dp[i][j] + dp[i-1][k])%M;
			}
		}
	}
	
	for (int i = 1; i < m+1; i++)
	{
		for (int j = 1; j < n+1; j++)
		{
			for (int k = j; k <= n; k++)
			{
				back[i][j] = (back[i][j] + back[i-1][k])%M;
			}
		}
	}
	
	ll sum = 0ll;

	for (int i = 1; i < n+1; i++)
	{
		for(int j = i; j < n + 1; j++)
			sum = (sum + dp[m][i]*back[m][j]%M)%M;
		// deb(dp[m][i]); deb(back[m][i]);
	}
	
	
	cout << sum << "\n";
	return 0;
}
