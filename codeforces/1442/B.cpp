#include <bits/stdc++.h> 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")

using namespace std; 

const int MOD = 998244353;

void solve(){
    int n,k;
    cin >> n >> k;
    
    vector<int> b(n, 0);
    vector<int> pos(n+2, 0);
    vector<int> cnt(n+2, 0);
    cnt[0] = cnt[n+1] = -1;
    
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pos[x] = i+1;
    }
    
    for (int i = 0; i < k; i++)
    {
        cin >> b[i];
        cnt[pos[b[i]]] = -1;
    }
    
    int64_t ans = 1;
    
    for (int i = 0; i < k; i++)
    {
        int p = pos[b[i]];
        int64_t curr = 0;
        if(cnt[p-1] != -1) curr++;
        if(cnt[p+1] != -1) curr++;
        ans = (ans * curr) %  MOD;
        cnt[p] = 0;
    }
    
    cout << ans << "\n";
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
