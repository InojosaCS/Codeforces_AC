#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define debug(x) cout << (#x) << " is " << (x) << endl
#define int long long

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);
	
	int n,m;
	cin >> n >> m;
	vector<vector<int>> g(n+1);
	
	for (int i = 0; i < m; i++)
	{
		int a,b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	vector<int> expected(n+1), asigned(n+1,0);
	vector<pair<int,int>> order(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> expected[i+1];
		order[i] = {expected[i+1], i+1ll};
	}
	
	sort(all(order));
	bool valid = true;
	vector<int> ans;
	
	for (auto par: order)
	{
		int d,p,sum=0ll;
		tie(d,p) = par;
		set<int> s;
		for(int x: g[p]){
			if(asigned[x] > d) continue;
			else if(asigned[x] == d) valid = false;
			else s.insert(asigned[x]);
		}
		for(auto x: s) sum += x;
		
		if(sum == d*(d-1ll)/2ll && valid) {
			ans.push_back(p);
			asigned[p] = d;
		}else{
			valid = false;
			break;
		}
	}
	
	if(valid){
		for(int x: ans){
			cout << x << " ";
		}
		cout << "\n";
	}else{
		cout << "-1\n";
	}

}
