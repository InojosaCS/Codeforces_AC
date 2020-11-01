#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g(3e5);
vector<int64_t> a(3e5, 0);
vector<int64_t> cnt(3e5, 0);
vector<int64_t> mx(3e5, 0);
vector<int64_t> sum(3e5, 0);
vector<bool> visited(3e5, 0);

void dfs(int u){
    visited[u] = true;
    
    for(int v: g[u]){
        if(!visited[v]){
            dfs(v);
            cnt[u] += cnt[v];
            sum[u] += sum[v];
            mx[u] = max(mx[u], mx[v]);
        }
    }
    int64_t helper = sum[u] / cnt[u] + (sum[u] % cnt[u] > 0);
    mx[u] = max(mx[u], helper);
}

void solve() {
    int n;
    cin >> n;
    
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        g[x].push_back(i);
    }
    
    for (int i = 0; i < n; i++)
        cin >> sum[i+1];
    
    for (int i = 0; i < n; i++)
    {
        if((int) g[i+1].size() == 0){
            cnt[i+1] = 1;
            mx[i+1] = sum[i+1];
        }
    }
    
    dfs(1);
    cout << mx[1] << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int32_t tt = 1;
    //cin >> tt;

    while(tt-->0) solve();

    return 0;
}
