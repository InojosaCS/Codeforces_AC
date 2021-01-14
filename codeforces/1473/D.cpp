#include <bits/stdc++.h> 

using namespace std; 

void solve(int test){
    int n, m;
    cin >> n >> m;
    
    string s;
    cin >> s;
    
    s = "#" + s + "#";
    
    vector<int> pos(n+2, 0);
    vector<int> neg(n+2, 0);
    vector<int> mx(n+2, 0);
    vector<int> mn(n+2, 0);
    
    for (int i = 1; i <= n; i++)
    {
	neg[i] += (s[i] == '-') + neg[i-1];
	pos[i] += (s[i] == '+') + pos[i-1];
	mn[i] = min(mn[i-1], pos[i] - neg[i]);
	mx[i] = max(mx[i-1], pos[i] - neg[i]);
    }

    int all = pos[n] - neg[n];
    vector<int> mx2(n+2, all);
    vector<int> mn2(n+2, all);
    
    for (int i = n; i >= 1; i--)
    {
	all += (s[i] == '-') ? 1 : -1;
	mn2[i] = min(mn2[i+1], all);
	mx2[i] = max(mx2[i+1], all);
    }
    
    for (int i = 0; i < m; i++)
    {
	int l, r;
	cin >> l >> r;
	
	int diff = (pos[r] - pos[l-1]) - (neg[r] - neg[l-1]);
	int lb = min(mn[l-1], mn2[r+1] - diff);
	int ub = max(mx[l-1], mx2[r+1] - diff);
	cout << ub - lb + 1 << "\n";
    }
    
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int32_t testCases = 1;
    cin >> testCases;
    
    while(testCases-->0) solve(testCases + 2);
    
    return 0;
}	
