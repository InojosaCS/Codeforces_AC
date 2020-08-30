#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << "\n";
#define debv(v) for (auto usb: v) cout << usb << " "; cout << "\n";

// n == (1 \/ 0) ????, memory?

ll pow(ll a, ll b){
	if(a*a > 1e18) return 0;
	if(b == 0) return 1LL;
	if(b == 1) return a;
	return pow(a*a, b/2) * pow(a, b%2);
}

void solve(){
	ll n, total = 0LL;
	cin >> n;
	vector<ll> a(n);
	
	for (int i = 0; i < n; i++){
		cin >> a[i];
		total += a[i];
	}
	
	sort(all(a));
	ll ans = 1e18;
	bool fine = true;
	
	for (ll i = 1; ; i++)
	{
		ll sum = 0ll;
		ll ci = 1LL;
		
		for (int j = 0; j < n && fine; j++)
		{
			sum += abs(ci-a[j]);
			if(j == n - 1) continue;
			if(ci > 1e18 / i) fine = false;
			ci *= i;
		}
		
		if(!fine){
			break;
		}
		
		if(sum > ans) break;
		ans = min(ans, sum);
	}
	
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(20);	

	int t = 1;
	//cin >> t;

	while(t--) solve();
	//cout << "OK\n";
	
	return 0;
}
