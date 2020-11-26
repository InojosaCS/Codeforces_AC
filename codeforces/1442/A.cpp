#include <bits/stdc++.h> 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")

using namespace std; 

void solve(){
    int n;
    cin >> n;
    
    vector<int> a(n+1);
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i+1];
    }

    a[0] = 0;
    int mn = 1e9;
    
    for (int i = 1; i <= n; i++)
    {
        int copy = a[i];
        mn = min(a[i], mn);
        a[i] -= mn;
        a[i] = max(a[i], min(a[i-1], copy));
        mn = min(copy - a[i], mn);
    }
    
    //for (int i = 0; i < n; i++)
    //{
        //cout << a[i+1] << " \n"[i == n-1];
    //}
    
    reverse(a.begin(), a.end());
    mn = 1e9;
    string ans = "YES\n";
    
    for (int i = 0; i < n; i++)
    {
        mn = min(a[i], mn);
        a[i] -= mn;
        if(a[i]) ans = "NO\n";
    }
    
    cout << ans;
}
    
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    //freopen("output.txt", "w", stdout);
    
	int32_t tt = 1;
	cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}
