#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int64_t> a(n+1,0);
	vector<int64_t> b(n+1,0);
	
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
		cin >> b[i];
		
	vector<pair<int64_t, int64_t>> p(n+1);
	
	for (int i = 0; i < n+1; i++)
		p[i] = {a[i], b[i]};

	sort(p.begin(), p.end());
	
	vector<int64_t> pref(n+2,0);
	
	for (int i = n; i > -1; i--)
	{
		pref[i] += pref[i+1] + p[i].second;
	}
	
	int64_t best = *max_element(a.begin(), a.end());
	
	for (int i = 0; i < n+1; i++)
	{
		int64_t curr = max(p[i].first, pref[i+1]);
		best = min(best, curr);
		//cout << p[i].first << " "<< pref[i+1] << "\n";
	}
	
	cout << best << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int32_t tt = 1;
	cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}	
