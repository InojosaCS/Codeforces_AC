#include <bits/stdc++.h>

using namespace std;

void solve(){
	int64_t n, m;
	cin >> n >> m;
	
	vector<pair<int64_t,int64_t>> a(m);
	vector<int64_t> pref(m + 1, 0);
	vector<int64_t> left(m, 0);
	
	for (int i = 0; i < m; i++)
	{
		cin >> a[i].first >> a[i].second;
		left[i] = -a[i].first;
	}
	
	sort(left.begin(), left.end());
	
	for (int i = 1; i <= m; i++)
		pref[i] += pref[i-1] - left[i-1];
	
	int64_t ans = 0;
	
	for (int i = 0; i < m; i++)
	{
		auto low = lower_bound(left.begin(), left.end(), -a[i].second);
		int64_t cnt = min(n-1, (int64_t)(low - left.begin()));
		//if(cnt > m-1){
			//cout << "i: " << i << " cnt: " << cnt << " epale " << low - left.begin() << "\n";
			//continue;
		//}
		int64_t rest = n - 1 - cnt;
		int64_t current = a[i].first + rest * a[i].second + pref[cnt];
		if(cnt && a[i].first >= -left[cnt-1]){
			int64_t helper = a[i].second;
			if(cnt < m) helper = max(helper, -left[cnt]);
			current += helper - a[i].first;
		}
		ans = max(ans, current);
	}
	
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int32_t tt = 1;
	cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}	
