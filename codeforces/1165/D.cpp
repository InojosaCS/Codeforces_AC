#include <bits/stdc++.h> 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")

using namespace std; 

void solve(){
    int n;
    cin >> n;
    vector<int64_t> a(n);
    vector<int64_t> div;
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    
    int64_t ans = a[0] * a[n-1];
    
    for (int64_t i = 2; i*i <= ans && (int) div.size() <= n; i++)
    {
        if(i*i == ans) div.push_back(i);
        else if(ans % i == 0) {
            div.push_back(i);div.push_back(ans/i);
        }
    }
    
    sort(div.begin(), div.end());
    
    if(div != a){
        ans = -1;
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
