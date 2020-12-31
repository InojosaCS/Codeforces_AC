#include <bits/stdc++.h> 

using namespace std; 

void solve(){
    int n;
    cin >> n;
    
    vector<int> degree(n, 0);
    vector<int> w(n);
    
    for (int i = 0; i < n; i++)
	cin >> w[i];
    
    int64_t sum = 0;
    
    for (int i = 0; i < n; i++)
	sum += w[i];
    
    for (int i = 0; i + 1 < n; i++)
    {
	int u, v;
	cin >> u >> v;
	u--; v--;
	degree[u]++;
	degree[v]++;
    }
    
    cout << sum << " ";
    priority_queue<pair<int,int>> pq;
    
    for (int i = 0; i < n; i++)
    {
	if(degree[i] > 1) pq.push({w[i], degree[i]});
    }
    
    for (int i = 0; i + 2 < n; i++)
    {
	int64_t x, d;
	tie(x,d) = pq.top();
	pq.pop();
	sum += x;
	cout << sum << " ";
	d--;
	if(d > 1) pq.push({x, d});
    }
    
    cout << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int32_t testCases = 1;
    cin >> testCases;

    while(testCases-->0) solve();
    
    return 0;
}	
