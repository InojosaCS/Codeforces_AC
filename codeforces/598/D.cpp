#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;
#define debv(v) for (auto x: v) cout << x << " "; cout << "\n";

const int N = 1007;
bool g[N][N];
ll p[N][N], cc[N][N], visited[N][N],dx[] = {-1, 0, 0, 1}, dy[] = {0, 1, -1, 0};
map<ll,ll> val;

void dfs(ll x, ll y, ll c){
	visited[x][y] = cc[x][y] = c;
	val[c] += p[x][y];
	
	for(int i = 0; i < 4; i++)
		if(x+dx[i]>0 && y+dy[i]>0 && g[x+dx[i]][y+dy[i]] && !visited[x+dx[i]][y+dy[i]]) 
			dfs(x + dx[i], y + dy[i], c);
	
	return;
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);	
	
	int n,m,k;
	cin >> n >> m >> k;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char x;
			cin >> x;
			if(x == '.'){
				g[i+1][j+1] = true;
			}else{
				for(int q = 0; q < 4; q++)
					p[i + 1 + dx[q]][j + 1 + dy[q]]++;
			}
		}
	}
	
	ll cnt = 1;
	 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(g[i+1][j+1] && !visited[i+1][j+1]){
				dfs(i + 1, j + 1, cnt);
				cnt++;
			}
		}	
	}
	
	for (int i = 0; i < k; i++)
	{
		ll a,b;
		cin >> a >> b;
		cout << val[cc[a][b]] << "\n";
	}
	
	
	return 0;
}
