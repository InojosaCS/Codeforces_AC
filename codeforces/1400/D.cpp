#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int64_t> a(n+1, 0LL);
    vector<vector<int64_t>> cnt(n+1, vector<int64_t>(n+1, 0));
    
    for (int i = 1; i < n+1; i++)
    {
        cin >> a[i];
        cnt[a[i]][i]++;
        for (int x = 1; x < n+1; x++)
        {
            cnt[x][i] += cnt[x][i-1];
        }
    }
    
    int64_t ans = 0;
    
    for (int x = 1; x < n+1; x++)
    {   
        int j = a[x];
        for (int y = x+1; y < n+1; y++)
        {
            int k = a[y];
            ans += cnt[k][x-1] * (cnt[j][n] - cnt[j][y]);
        }
    }
        
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int32_t tt = 1;
    cin >> tt;

    while(tt--) solve();

    return 0;
}
