#include <bits/stdc++.h>
 
using namespace std;

#define int int64_t

void solve(){
    int64_t n, m;
    cin >> n >> m;
    int a[n][m];
    
    for (int i = 0; i < n; i++)
    {
	string s;
	cin >> s;
	for (int j = 0; j < m; j++)
	{
	    a[i][j] = s[j] - '0';
	}
    }
    
    vector<tuple<int,int,int,int,int,int>> ans;
    
    for (int i = 1; i < n; i++)
    {
	for (int j = 1; j < m; j++)
	{
	    int curr = a[i][j] + a[i-1][j] + a[i-1][j-1] + a[i][j-1];
	    vector<tuple<int,int,int>> help(4);
	    help[0] = {a[i][j], i, j};
	    help[1] = {a[i-1][j], i-1, j};
	    help[2] = {a[i-1][j-1], i-1, j-1};
	    help[3] = {a[i][j-1], i, j-1};
	    sort(help.rbegin(), help.rend());
	    //cout << curr << "\n";
	    int a1, a2, a3, a4, a5, a6, a7, a8, xz;
	    tie(xz, a1, a2) = help[0];
	    tie(xz, a3, a4) = help[1];
	    tie(xz, a5, a6) = help[2];
	    tie(xz, a7, a8) = help[3];
	    
	    if(curr == 0) continue;
	    if(curr == 4){
		ans.push_back({a3, a4, a5, a6, a7, a8});
		curr = 1;
		a[a3][a4] = a[a5][a6] = a[a7][a8] = 0;
		help[0] = {a[i][j], i, j};
		help[1] = {a[i-1][j], i-1, j};
		help[2] = {a[i-1][j-1], i-1, j-1};
		help[3] = {a[i][j-1], i, j-1};
		sort(help.rbegin(), help.rend());
		
		tie(xz, a1, a2) = help[0];
		tie(xz, a3, a4) = help[1];
		tie(xz, a5, a6) = help[2];
		tie(xz, a7, a8) = help[3];
	    }
	    
	    if(curr == 1){
		ans.push_back({a1, a2, a3, a4, a5, a6});
		curr = 2;
		a[a1][a2] = 0;
		a[a3][a4] = a[a5][a6] = 1;
		help[0] = {a[i][j], i, j};
		help[1] = {a[i-1][j], i-1, j};
		help[2] = {a[i-1][j-1], i-1, j-1};
		help[3] = {a[i][j-1], i, j-1};
		sort(help.rbegin(), help.rend());
		
		tie(xz, a1, a2) = help[0];
		tie(xz, a3, a4) = help[1];
		tie(xz, a5, a6) = help[2];
		tie(xz, a7, a8) = help[3];
	    }
	    
	    if(curr == 2){
		ans.push_back({a3, a4, a5, a6, a7, a8});
		curr = 3;
		a[a3][a4] = 0;
		a[a7][a8] = a[a5][a6] = 1;
		help[0] = {a[i][j], i, j};
		help[1] = {a[i-1][j], i-1, j};
		help[2] = {a[i-1][j-1], i-1, j-1};
		help[3] = {a[i][j-1], i, j-1};
		sort(help.rbegin(), help.rend());
		
		tie(xz, a1, a2) = help[0];
		tie(xz, a3, a4) = help[1];
		tie(xz, a5, a6) = help[2];
		tie(xz, a7, a8) = help[3];
	    }
	    if(curr == 3){
		ans.push_back({a1, a2, a3, a4, a5, a6});
		curr = 0;
		a[a1][a2] = a[a3][a4] = a[a5][a6] = 0;
	    }
	}
    }
    
    for (int i = 0; i < n; i++)
    {
	for (int j = 0; j < m; j++)
	{
	    //cout << a[i][j] << " \n"[j == m-1];
	    assert(a[i][j] == 0);
	}
    }
    
    assert((int) ans.size() <= 3*n*m);
    
    cout << ans.size() << "\n";
    
    for(auto t: ans){
	int a1, a2, a3, a4, a5, a6;
	tie(a1, a2, a3, a4, a5, a6) = t;
	cout << a1+1 << " " << a2+1 << " " << a3+1 << " " << a4+1 << " " << a5+1 << " " << a6+1 << "\n";
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
