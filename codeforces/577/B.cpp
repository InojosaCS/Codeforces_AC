#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;

void solve() {
    int n,m;
    cin >> n >> m;
    
    vector<int> a(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] = a[i] % m;
    }
    
    sort(a.begin(), a.end());
    vector<int> visited(5000, 0);
    visited[0] = 1;
    
    for (int i = 0; i < n; i++)
    {
        vector<int> aux = visited;
        for (int j = m; j >= 0; j--)
        {
            if(visited[j]) aux[(j + a[i]) % m]++;
        }
        
        visited = aux;
        
        //for (int j = 0; j < m; j++)
            //cout << visited[j] << (j==m-1?"\n":" ");
        
        if(visited[0] > 1) {
            cout << " YES\n";
            return;
        }
    }
    
    if(visited[0] > 1) cout << "YES\n";
    else cout << "NO\n";
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int32_t tt = 1;
    //cin >> tt;

    while(tt--) solve();

    return 0;
}
