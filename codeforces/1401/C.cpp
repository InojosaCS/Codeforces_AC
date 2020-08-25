#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << "\n";
#define debv(v) for (auto usb: v) cout << usb << " "; cout << "\n";

// n == (1 \/ 0) ????, memory?

void solve(){
	ll n;
	cin >> n;
	vector<ll> a(n), copy(n);
	ll mn = 1e18;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		copy[i] = a[i];
		mn = min(mn, a[i]);
	}
	sort(all(copy));
	string ans = "YES\n";
	
	for (int i = 0; i < n; i++)
	{
		if(!(a[i] == copy[i] || a[i] % mn == 0)){
			ans = "NO\n";
			break;
		}
	}
	
	cout << ans;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(20);	

	int t = 1;
	cin >> t;

	while(t--) solve();
	//cout << "OK\n";
	
	return 0;
}
