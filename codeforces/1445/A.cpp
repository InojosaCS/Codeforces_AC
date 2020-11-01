#include <bits/stdc++.h>

using namespace std;

void solve() {
    int64_t n, x;
    cin >> n >> x;
    vector<int64_t> a(n);
    vector<int64_t> b(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        cin >>  b[i];
    }
    
    sort(a.begin(), a.begin());
    sort(b.begin(), b.begin());
    
    for (int i = 0; i < n; i++)
    {
        int ind = -1;
        int64_t mn = 0;
        for (int j = 0; j < n; j++)
        {
            if(a[i] + b[j] <= x && b[j] > mn){
                mn = b[j];
                ind = j;
            }
        }
        if(ind == -1){
            cout << "No\n";
            return;
        }
        b[ind] = 1e18;
    }
    cout << "Yes\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int32_t tt = 1;
    cin >> tt;

    while(tt-->0) solve();

    return 0;
}
