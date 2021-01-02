#include <bits/stdc++.h> 
 
using namespace std; 

void solve(int test){
    int n, m;
    cin >> n >> m;
    
    string a, b;
    cin >> a >> b;
    
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    
    for (int i = 1; i <= n; i++)
    {
	for (int j = 1; j <= m; j++)
	{
	    if(a[i-1] == b[j-1]){
		dp[i][j] = dp[i-1][j-1] + 2;
	    } else {
		dp[i][j] = max(dp[i-1][j], dp[i][j-1]) - 1;
	    }
	    
	    dp[i][j] =  max(dp[i][j], 0);
	}
    }
    
    int ans = 0;
    
    for (int i = 0; i <= n; i++)
    {
	for (int j = 0; j <= m; j++)
	{
	    ans = max(ans, dp[i][j]);
	}
    }
    
    cout << ans << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int32_t testCase = 1;
    //cin >> testCase;

    while(testCase-->0) solve(testCase);
    
    return 0;
}	
