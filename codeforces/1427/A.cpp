#include <bits/stdc++.h>
 
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int64_t> a(n);
	int64_t pos = 0;
	int64_t neg = 0;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(a[i] >= 0) pos += a[i];
		else neg -= a[i];
	}
	
	if(neg == pos){
		cout << "NO\n";
		return;
	} else if(neg<=pos){
		sort(a.rbegin(), a.rend());
	} else {
		sort(a.begin(), a.end());
	}
	
	cout << "YES\n";
	
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	
	cout << "\n";
	return;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	int tt = 1;
	cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}
