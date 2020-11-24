#include <bits/stdc++.h> 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")

using namespace std; 

void solve(){
    int64_t n, old;
    cin >> n;
    old = n;
    vector<pair<int,int>> list;
    
    for (int64_t i = 2; i*i <= n; i++)
    {
	int cnt = 0;
	while(n % i == 0){
	    n /= i;
	    cnt++;
	}
	if(cnt) list.push_back({cnt, i});
    }
    
    if(n > 1) list.push_back({1, n});
    
    sort(list.rbegin(), list.rend());
    
    int64_t a = list[0].first;
    int64_t b = list[0].second;
    int64_t d = 1;
    
    cout << a << "\n";
    
    for (int i = 0; i+1 < a; i++)
    {
	cout << b << " ";
	d *= b;
    }
    
    cout << old / d << "\n";
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int32_t tt = 1;
    cin >> tt;

    while(tt-->0) solve();
    
    return 0;
}	
