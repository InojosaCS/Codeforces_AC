#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define debug(x) cout << (#x) << " is " << (x) << endl
#define ll long long
 
std::vector<std::set<int> > graph(1e5+7);
std::vector<int> deg(1e5+7,0), degO(1e5+7,0);
std::vector<int> visited(1e5+7,0), dist(1e5+7,0);
 
void dfs(int u, int cnt){
	visited[u] = 1;
	dist[u] = cnt;
	for(auto x: graph[u])
		if(!visited[x]){
			dfs(x, cnt+1);
		}
	return;
}
 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);
 
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n-1; ++i)
	{
		int a,b;
		cin >> a >> b;
		graph[a].insert(b);
		graph[b].insert(a);
		deg[a]++; degO[a]++;
		deg[b]++; degO[b]++;
	}
 
	int mx = 0;
 
	for (int i = 0; i < n+1; ++i)
	{
		if(deg[i]==1){
			dfs(i,0); 
			for (int j = 0; j < n+1; ++j)
				mx = max(dist[j], mx);
			break;
		}
	}
 	
 	if(k>mx){
 		cout << "NO\n";
 		return 0;
 	}
 
 	queue<int> q;
 
 	for (int i = 0; i < n+1; ++i)
 		if(deg[i]==1)
 			q.push(i);
 
 	int cnt = 0;
 	bool fake = false;
 
 	while(q.size() && cnt<k-1){
 		
	 	set<int> temp;
 		while(q.size()){
	 		int current = q.front();
	 		q.pop();
	 		deg[current] = 0;
	 		// debug(current);
	 		for(auto x: graph[current]){
	 			if(degO[x]<=3){
	 				fake = true;
	 			}
	 			deg[x]--;  
	 			temp.insert(x);
	 			graph[x].erase(current);
	 		}
 		}
 		// debug(cnt);
 		for (auto x: temp){
 			q.push(x);
 			if(deg[x]!=1)
 				fake = true;
 		}
 		
 		cnt++;
 	}
 	// int p = 0;
 	// for(auto s: graph){
 	// 	cout << p << ", " << deg[p] << ": ";
 	// 	for(auto x :  s){
 	// 		cout << x << " ";
 	// 	}
 	// 	cout << "\n";
 	// 	p++;
 	// 	if(p>n) break;
 	// }
 	int limit = 0, ones = 0;
 	for (int i = 0; i < n+1; ++i)
 	{	
 		if(deg[i]>=3)
 	 		limit++;
 	 	if(deg[i]==1)
 	 		ones++;
 	 }
 		
 	if(limit == 1 && ones && !fake){
 		cout << "YES\n";
 	}else{
 		cout << "NO\n";
 	}
 
	return 0;
}