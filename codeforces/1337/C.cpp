#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<ii> vii;
 
#define solve imAwesome
#define for0(i,n) for(int i=0; i<(int)n; i++)
#define forn(i,n) for(int i=1; i<=(int)n; i++)
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define all(x) x.begin(),x.end()
#define endl cout << "\n";
#define debug cout << "Aqui\n";
 
//ifstream fin ("subset.in");
//ofstream fout ("subset.out");
 
vector <vll> graph;
vector <bool> visited(1e6);
vll dist;
ll n,m;
 
ll dfs(ll i, ll cnt){
	
	ll size = 1ll;
	visited[i]=true;
	
	for(auto x: graph[i]){
		if(!visited[x]) size += dfs(x, cnt + 1ll);
	}
	
	dist.pb(size-cnt);
	//cout << i << ": " << cnt << " & " << size << "\n"; 
	return size;
 
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	//ifstream cin ("subset.in");
	//ofstream cout ("subset.out");
	
	ll a,b,k;
	
	cin >> n >> k;
	
	for(int i=0; i<n+1; i++) {
		vll aux;
		graph.pb(aux);
	}
	
	for(int i=0; i<n-1; i++) {
		cin >> a >> b;
		graph[a].pb(b); graph[b].pb(a);
	}
	
	dfs(1ll,1ll);
	
	sort(all(dist), greater<ll>());
	ll ans =0;
	//for(int i=0; i<n-k; i++) cout << dist[i] << " ";
	//endl
	
	for(int i=0; i<n-k; i++) ans += dist[i];
	
	cout << ans << "\n";
	return 0;
 
}
 
 