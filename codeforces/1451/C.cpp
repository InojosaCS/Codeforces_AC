#include <bits/stdc++.h> 
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")

using namespace std; 

void solve(){
    int64_t  n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    string ans = "YES\n";
    
    vector<int> cnta(28, 0);
    vector<int> cntb(28, 0);
    
    for (int i = 0; i < n; i++)
    {
        cnta[a[i] - 'a' + 1]++;
        cntb[b[i] - 'a' + 1]++;
    }
    
    for (int i = 1; i < 28; i++)
    {
        cnta[i] += cnta[i-1] - (cnta[i-1]%k);
        if(cntb[i] > cnta[i]){
            ans = "NO\n";
            break;
        } else {
            cnta[i] -= cntb[i];
        }
    }
    
    cout << ans;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int32_t tt = 1;
	cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}
