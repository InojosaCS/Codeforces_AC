#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;
#define debv(v) for (auto x: v) cout << x << " "; cout << "\n";

int m;
map<tuple<int,int,int>, bool> visited;
bitset<11> val;
map<tuple<ll,ll,ll>,tuple<ll,ll,ll>> parent;
bool done = false;

void dfs(int x, int y, int z){
	if(z == m || done){
		// cout << x << " " << y << " " << z << "\n";
		done = visited[{x,y,z}] = true;
		return;
	}
	
	visited[{x,y,z}] = true;
	int helper = (z%2) ? -1 : 1;
	for (int i = 1; i <= 10; i++)
	{
		bool aux = (z%2) ? x-i < 0 : x+i > 0;
		if(val[i] && i!=y && aux && !visited[{x + helper*i, i, z+1}]){
			// cout << i << ": " << x << " " << y << " " << z << "\n";
			parent[{x + helper*i, i, z+1}] = {x,y,z};
			dfs(x + helper*i, i, z+1);
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);	
	
	string s;
	cin >> s;
	
	for (int i = 0; i < 10; i++) val[i+1] = s[i]-'0';
	
	cin >> m;
	dfs(0,0,0);
	
	int a,b,c;
	a = b = c = 0;
	
	for(int i = -10; i<=10; i++){
		for (int j = 1; j <= 10; j++){
			if(visited[{i,j,m}]){
				a = i;
				b = j;
				c = m;
			}
		}
	}
	
	if(a || b || c){
		cout << "YES\n";
		vector<ll> ans;
		while(a && b && c){
			//cout << a << " " <<  b  << " " << c << "\n";
			ans.push_back(b);
			ll p,q,r;
			tie(p,q,r) = parent[{a,b,c}];
			a = p;
			b = q;
			c = r;
		}
		reverse(all(ans));
		debv(ans);
		assert(sz(ans) == m);
	}else{
		cout << "NO\n";
	}
	
	return 0;
}
