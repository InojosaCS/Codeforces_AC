#include <bits/stdc++.h> 
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")

using namespace std; 

void solve(){
    int n, m;
    cin >> n >> m;
    
    vector<int> v(n+1, 1e9);
    
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    int l = 0, r = m;
    int ans = m - 1;
    
    while(l < r){
        int mid = (l+r) / 2;
        vector<int> a = v;
        //cout << mid << "\n";
        //for (int i = 0; i < n; i++)
            //cout << a[i] << " \n"[i == n-1];

        for (int i = n-1; i > -1; i--)
        {
            if(a[i] > a[i+1]){
                int temp = (a[i] + mid) % m;
                if(temp < a[i]){
                    a[i] = min(temp, a[i+1]);
                } 
                continue;
            }
            int add = min(m-1-a[i], mid);
            a[i] += add;
            a[i] = min(a[i], a[i+1]);
            assert(a[i] < m);
        }
        
        bool ok = true;
        
        for (int i = 0; i < n; i++)
        {
            if(a[i] > a[i+1]) ok = 0;
            //cout << a[i] << " \n"[i == n-1];
        }
        
        if(ok){
            r = mid;
            ans = mid;
        } else {
            l = mid+1;
        }
    }
    
    cout << ans << "\n";
}
    
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    //freopen("output.txt", "w", stdout);
    
	int32_t tt = 1;
	//cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}
