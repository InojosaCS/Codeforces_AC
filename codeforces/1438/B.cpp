#include <bits/stdc++.h> 

using namespace std; 


void solve(){
    int n;
    cin >> n;
    set<int> s;
    
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    
    if(s.size() == n) cout << "NO\n";
    else cout << "YES\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int32_t tt = 1;
	cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}	
