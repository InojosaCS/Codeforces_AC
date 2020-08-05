#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;
#define debv(v) for (auto x: v) cout << x << " "; cout << "\n";


vector<vector<ll>> g(1e5+7);
vector<ll> parent(1e5+7,0),degree(1e5+7, 0ll), son(1e5+7,0);
vector<bool> visited(1e5+7,false);

void dfs(ll u){
	visited[u] = true;
	//deb(u);
	for(ll v: g[u]){
		if(!visited[v]){
			parent[v] = u;
			//cout << u << " " << v << " edge \n";
			dfs(v);
			son[u] += son[v];
		}
	}
	if(degree[u] == 1) son[u] = 1ll;
	return;
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);	
	
	int tt;
	cin >> tt;
	while(tt--){
		ll n,s,w=0ll;
		cin >> n >> s;
		priority_queue<tuple<ll,ll,ll>> q;
		map<pair<ll,ll>,ll> edge;
		
		for (int i = 0; i < n-1; i++)
		{
			ll a,b,c;
			cin >> a >> b >> c;
			a--; b--;
			g[a].push_back(b);
			g[b].push_back(a);
			edge[{a,b}] = edge[{b,a}] = c;
			degree[a]++;
			degree[b]++;
		}
		
		dfs(0);
		ll ans = 0ll;
		for (int i = 1; i < n; i++)
		{
			//cout << i+1 << ": " << son[i] << " ||| edge: " << edge[{parent[i],i}]<< "\n";
			ll x = edge[{parent[i], i}], y = son[i];
			q.push({y*(x - x/2ll), x, y});
			w += edge[{parent[i], i}] * son[i];
		}
	
		while(w > s){
			ll p,x,y;
			tie(p,x,y) = q.top();
			q.pop();
			ans++;
			w -= p;
			x /= 2ll;
			q.push({y*(x - x/2ll), x, y});
		}
		cout << ans << "\n";
		
		for (int i = 0; i < n+3; i++)
		{
			visited[i] = false;
			parent[i] = degree[i] = son[i] = 0ll;
			g[i].erase(all(g[i]));
		}
	}
	
	return 0;
}
