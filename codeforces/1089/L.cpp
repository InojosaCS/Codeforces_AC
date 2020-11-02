#include <bits/stdc++.h>

using namespace std;

void solve(){
	int64_t n, k;
	cin >> n >> k;
	vector<int64_t> visited(k+1, 0);
	vector<int64_t> a(n, 0);
	vector<int64_t> cnt(n, 0);
	vector<pair<int64_t,int64_t>> b(n);
	
	for (int64_t i = 0; i < n; i++)
	{
		cin >> a[i];
		visited[a[i]]++;
	}
	
	for (int64_t i = 0; i < n; i++)
	{
		cin >> b[i].first;
		b[i].second = a[i];
	}
	
	sort(b.begin(), b.end());
	
	int64_t need = 0;
	
	for (int64_t i = 0; i < k; i++)
	{
		if(!visited[i+1]) need++;
	}
	
	int64_t ans = 0;
	
	for (int64_t i = 0; i < n && need; i++)
	{
		if(visited[b[i].second] > 1){
			visited[b[i].second]--;
			need--;
			ans += b[i].first;
		}
	}
	
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int32_t tt = 1;
	//cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}	
