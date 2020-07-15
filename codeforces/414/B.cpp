#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define debug(x) cout << (#x) << " is " << (x) << endl;
#define ll long long
 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);
 
	long long n,k,mod=1e9+7;
	cin >> n >> k;
	vector<vector<long long> > dp(k+1, std::vector<long long> (n+1, 0ll));
	vector<vector<long long> > divisors(2007);
	
	dp[0][1] = 1ll;
	
	for (int i = 1; i < 2007; ++i)
		for (int j = 1; j <= i; ++j)
			if(i%j==0)
				divisors[i].push_back(j);

	for (int i = 1; i <= k; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{	
			dp[i][j] = 0ll;
			for(auto x: divisors[j]){
			//	debug(x);
				dp[i][j] = (dp[i][j]+dp[i-1][x])%mod;
			}
		}
	}

	long long sum = 0ll;
	for (int i = 1; i <= n; ++i)
		sum = (sum+dp[k][i])%mod;

	cout << sum << "\n";
	return 0;
}