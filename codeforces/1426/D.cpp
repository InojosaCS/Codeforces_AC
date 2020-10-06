#include <bits/stdc++.h>
 
using namespace std;

void solve(){
	int n;
	cin >> n;
	set<int64_t> s = {0};
	int64_t sum = 0, ans = 0, x;
	
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		sum += x;
		if(s.count(sum)){
			sum = x;
			s = {0,x};
			ans++;
		} else {
			s.insert(sum);
		}
	}
	
	cout << ans << "\n";
	return;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	int tt = 1;
	//cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}
