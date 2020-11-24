#include <bits/stdc++.h> 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")

using namespace std; 

void solve(){
    int n;
    cin >> n;
    
    vector<int> a(n);
    
    for (int i = 0; i < n; i++)
    {
	a[i] = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
	cout << a[(i+1)%n] << " \n"[i == n-1];
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int32_t tt = 1;
    cin >> tt;

    while(tt-->0) solve();
    
    return 0;
}	
