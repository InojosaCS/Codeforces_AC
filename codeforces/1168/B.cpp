#include <bits/stdc++.h> 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")

using namespace std; 

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    

    int64_t ans = 0, tl = n;
    
    for (int i = n-1; i > -1; i--)
    {
        for (int j = 1; i + 2*j < tl; j++)
        {
            if(s[i] == s[i + j] && s[i] == s[i + 2*j]){
                tl = (i + 2*j);
                break;
            }
        }
        ans += n-tl;
        //cout << i << " - " << tl <<  " : " << ans << "\n";
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
