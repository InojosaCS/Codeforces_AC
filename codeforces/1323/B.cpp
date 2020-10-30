#include <bits/stdc++.h>

using namespace std;

void solve(){
	int64_t n,m,k;
	cin >> n >> m >> k;
	vector<int64_t> a(n+1,0);
	vector<int64_t> b(m+1,0);
	vector<int64_t> prefa(n+1,0);
	vector<int64_t> prefb(m+1,0);
	
	for (int64_t i = 0; i < n; i++)
	{
		cin >> a[i+1];
		prefa[i+1] = a[i+1] + prefa[i];
	}
	
	for (int64_t i = 0; i < m; i++)
	{
		cin >> b[i+1];
		prefb[i+1] = prefb[i] + b[i+1];
	}
	
	set<int64_t> sides;
	
	for (int64_t i = 1; i*i <= k; i++)
	{
		if(k % i == 0){
			sides.insert(i);
			sides.insert(k/i);
		}
	}
	
	map<int64_t,int64_t> cnt;
	
	for(int64_t side: sides){
		for (int64_t i = side; i <= m; i++)
		{
			if(prefb[i] - prefb[i-side] == side){
				cnt[side]++;
			}
		}
	}
	
	int64_t ans = 0;
	
	for (int64_t i = 1; i <= n; i++)
	{
		for(int64_t base : sides){
			int64_t height = k / base;
			if(height > m || base + i - 1 > n) continue;
			if(prefa[i+base-1] - prefa[i-1] == base) ans += cnt[height];
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
