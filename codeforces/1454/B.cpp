#include <bits/stdc++.h> 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")

using namespace std; 

void solve(){
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<int> cnt(n+10,0);
    
    for (int i = 0; i < n; i++)
    {
	cin >> a[i];
	cnt[a[i]]++;
    }
    
    int mn = 1e9;
    int ind = -1;
    
    for (int i = 0; i < n; i++)
    {
	if(cnt[a[i]] == 1 && a[i] < mn){
	    ind = i+1;
	    mn = a[i];
	}
    }
    
    cout << ind << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int32_t tt = 1;
    cin >> tt;

    while(tt-->0) solve();
    
    return 0;
}	
