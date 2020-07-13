#include <bits/stdc++.h>
 
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define debug(x) cout << (#x) << " is " << (x) << endl

vector<vector<long long>> graph(1e5+7, vector<long long>()), inverseGraph(1e5+7, vector<long long>()), scc;
std::vector<long long> cost(1e5+7);
std::vector<bool> visited(1e5+7,0), inverseVisited(1e5+7,0);
stack<int> topologicalOrder;
int n,m;

void dfs(int u){
	visited[u]=1;
	for(auto v: graph[u])
		if(!visited[v])
			dfs(v);
	topologicalOrder.push(u);
	return;
}

void dfsInverse(int u, int cnt){
	inverseVisited[u]=1;
	scc[cnt].push_back(u);
	for(auto v: inverseGraph[u])
		if(!inverseVisited[v])
			dfsInverse(v, cnt);
	
	return;
}

void solve(){

	for (int i = 0; i < n; ++i)
		if(!visited[i+1])
			dfs(i+1);

	int cnt = 0;
	while(topologicalOrder.size())
	{
		int i = topologicalOrder.top();
		if(!inverseVisited[i])
		{
			vector<long long> v;
			scc.push_back(v);
			dfsInverse(i, cnt);
			cnt++;
		}
		topologicalOrder.pop();
	}

	long long ans1 = 0ll, ans2 = 1ll, mod = 1e9+7;

	for(auto x: scc){
		long long mn = (1e9+7);
		for(auto y: x)
			mn = min(mn, cost[y]);
		
		long long cnt = 0ll;
		for(auto y: x)
			cnt = cost[y]==mn ? cnt + 1 : cnt;
		
		ans1 += mn;
		ans2 = (ans2*cnt)%mod;
	}
	cout << ans1 << " " << ans2 << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> cost[i+1];
	
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b);
		inverseGraph[b].push_back(a);
	}

	solve();
	return 0;
}
