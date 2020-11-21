#include <bits/stdc++.h> 
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")

using namespace std; 

int64_t num(vector<int> a){
    int64_t ans = 0, p = 1;
    for(int x: a){
        ans += 1LL* x * p;
        p *= 10;
    }
    return ans;
}


void solve(){
    string n;
    cin >> n;
    
    int m = n.size();
    int ans = 1e9;
    
    for (int i = 0; i < (1LL << m); i++)
    {
        vector<int> temp;
        for(int j = 0; j < m; j++){
            if((1<<j) & i){
                temp.push_back(n[j] - '0');
            }
        }
        reverse(temp.begin(), temp.end());
        if(temp.size() == 0) continue;
        int now = num(temp);
        if(now == 0) continue;
        //cout << now << "\n";
        int curr = m - temp.size();
        reverse(temp.begin(), temp.end());
        
        for (int j = 0; j  < (int) temp.size(); j++)
        {
            if(temp[j]) break;
            curr++;
        }
        
        int x = sqrt(now);
        bool ok = x*x == now;
        if(ok && curr < ans){
            ans = curr;
            //cout << now << " " << x << "\n";

        }
    }
    
    if(ans == 1e9) cout << -1 << "\n";
    else cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int32_t tt = 1;
	//cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}
