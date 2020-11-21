#include <bits/stdc++.h> 
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")

using namespace std; 

void solve(){
    int64_t  n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = '#' + s;
    
    for (int qq = 0; qq < q; qq++)
    {
        int l, r;
        cin >> l >> r;
        bool a = false;
        for (int i = 0; i < l; i++)
        {
            if(s[i] == s[l]) a = true;
        }
        for (int i = r+1; i <= n; i++)
        {
            if(s[i] == s[r]) a = true;
        }
        if(a){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
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
