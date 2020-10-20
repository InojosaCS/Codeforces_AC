#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int64_t, int64_t>>> g(1234);
vector<vector<int64_t>> dist(1234, vector<int64_t>(1234,1e18));

void dijkstra(int64_t x){
    priority_queue<pair<int64_t,int64_t>> pq;
    vector<bool> visited(1234, false);
    pq.push({0LL, x});
    dist[x][x] = 0LL;
    
    while(!pq.empty()){
        int64_t current = pq.top().second;
        pq.pop();
        if(visited[current]) continue;
        visited[current] = true;
        for(auto edge: g[current]){
            int64_t w = edge.second;
            int64_t next = edge.first;
            if(dist[x][current] + w < dist[x][next]){
                dist[x][next] = dist[x][current] + w;
                pq.push({-dist[x][next], next});
            }
        }
    }
}

void solve(){
    int64_t n,m,k;
    cin >> n >> m >> k;
    
    vector<pair<int64_t,int64_t>> edges(m);

    for (int64_t i = 0; i < m; i++)
    {
        int64_t a,b,c;
        cin >> a >> b >> c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
        edges[i] = {a, b};
    }
    
    for (int64_t i = 1; i <= n; i++){
        dist[i][i] = 0;
        dijkstra(i);
    }
    
    vector<pair<int64_t,int64_t>> looking(k);
    
    for (int64_t i = 0; i < k; i++)
        cin >> looking[i].first >> looking[i].second;
    
    int64_t ans = 1e18;
    
    for(auto now: edges){
        int64_t helper = 0;
        int64_t u = now.first;
        int64_t v = now.second;
        for(auto path: looking){
            int64_t x = path.first;
            int64_t y = path.second;
            helper += min(dist[x][y], min(dist[x][v] + dist[u][y], dist[x][u] + dist[v][y]));
        }
        //cout << helper << "\n";
        ans = min(helper, ans);
    }

    cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    
	int64_t tt = 1;
	//cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}
