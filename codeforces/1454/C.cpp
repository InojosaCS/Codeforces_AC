#include <bits/stdc++.h> 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")

using namespace std; 

void solve(){
    int n;
    cin >> n;
    
    vector<vector<int>> g(n+1, {0, n+1});
    vector<int> cnt(n+10,0);
    
    for (int i = 0; i < n; i++)
    {
	int x;
	cin >> x;
	g[x].push_back(i+1);
    }
    
    int ans = 1e9;
    
    for (int i = 0; i < n+1; i++)
    {
	int curr = 0;
	if((int) g[i].size() < 3) continue;
	sort(g[i].begin(), g[i].end());
	for(int j = 1; j < (int) g[i].size(); j++){
	    if(g[i][j] - g[i][j-1] == 1) continue;
	    curr++;
	}
	//cout << curr << "\n";
	ans = min(curr, ans);
    }
    
    
    cout << ans << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int32_t tt = 1;
    cin >> tt;

    while(tt-->0) solve();
    
    return 0;
}	
