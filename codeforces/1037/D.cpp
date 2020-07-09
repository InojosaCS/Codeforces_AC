#include <bits/stdc++.h>
 
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (long long) x.size()

vector<vector<int>> graph(1e6);
vector<int> path(1e6,0);
vector<int> traversal(1e6,0);
int n;
bool ans = true;

void bfs(){
	queue<int> q;
	q.push(1);
	vector<bool> visited(n+7, false);
	visited[1] = true;
	int cnt = 1;
	// cout << 1 << " ";

	while(q.size() && ans){
		int current = q.front();
		q.pop();
		set<int> s;

		for(auto x: graph[current]){
			if(!visited[x]){
				visited[x]=true;
				s.insert(x);
			}
		}

		for(int i=0; i<sz(s); i++){
			if(s.count(traversal[cnt])){
				q.push(traversal[cnt]);
				//cout << traversal[cnt] << " ";
			}else{
				ans = false;
				break;
			}
			cnt++;
		}
	}
}

int main(){
	
	cin >> n;
	
	for (int i = 0; i < n-1; ++i)
	{
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}


	for (int i = 0; i < n; ++i)
		cin >> traversal[i];

	ans = (traversal[0]==1);
	bfs();
	cout << (ans ? "YES\n" : "NO\n");

	return 0;
}
