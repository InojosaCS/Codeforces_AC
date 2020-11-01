#include <bits/stdc++.h>

using namespace std;

const int64_t m = 998244353;

int64_t ppow(int64_t a, int64_t b){
	if(b == 0) return 1LL;
	if(b == 1) return a;
	return ppow(a*a%m, b/2) * (b%2 ? a : 1LL) % m;
}

int64_t inv(int64_t var){
	return ppow(var, m-2) % m;
}

void solve() {
    int n;
    cin >> n;
    vector<int64_t> a(2*n);
    
    for (int i = 0; i < 2*n; i++)
    {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    vector<int64_t> fact(2*n+7, 1);
        
    for (int i = 0; i < 2*n + 5; i++)
    {
        fact[i+1] = fact[i] * (i+1LL) % m;
    }
    
    int64_t ch = (fact[2*n] * inv(fact[n] * fact[n] % m)) % m;
    int64_t neg = 0, pos = 0;
    
    for (int i = 0; i < n; i++)
    {
        neg = (neg + ch * a[i] % m) % m;
    }
    for (int i = n; i < 2*n; i++)
    {
        pos = (pos + ch * a[i] % m) % m;
    }
    
    cout << (pos - neg + m) % m << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int32_t tt = 1;
    //cin >> tt;

    while(tt-->0) solve();

    return 0;
}
