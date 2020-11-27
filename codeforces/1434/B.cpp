#include <bits/stdc++.h> 
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")

using namespace std; 

void solve(){
    int n;
    cin >> n;
    
    vector<pair<char, int>> queries(2*n);
    int p = 0;
    set<pair<int,int>> s;
    
    for (int i = 0; i < 2*n; i++)
    {
        char c;
        int x = 0;
        cin >> c;
        if(c == '-') cin >> x;
        else s.insert({i, p++});
        queries[i] = {c, x};
    }
    
    vector<int> ans(n);
    
    for (int i = 0; i < 2*n; i++)
    {
        if(queries[i].first == '-') {
            if((int) s.size() == 0){
                cout << "NO\n";
                return;
            }
            auto it = s.lower_bound({i, -1});
            if(it == s.begin()){
                cout << "NO\n";
                return;
            }
            it--;
            int b = (*it).second;
            ans[b] = queries[i].second;
            s.erase(it);
            //cout << b << "\n";
        }
    }
    
    priority_queue<int> check;
    p = 0;
    
    for (int i = 0; i < 2*n; i++)
    {
        if(queries[i].first == '+'){
            check.push(-ans[p++]);
        } else {
            if((int) check.size() == 0 || -check.top() != queries[i].second){
                cout << "NO\n";
                return;
            }
            check.pop();
        }
    }
    
    //assert((int) ans.size() == n);
    
    cout << "YES\n";
    
    for (int i = 0; i < (int) ans.size(); i++)
    {
        cout << ans[i] << " \n"[i == n-1];
    }
    
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
