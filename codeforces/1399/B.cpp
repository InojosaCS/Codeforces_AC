#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;
#define debv(v) for (auto x: v) cout << x << " "; cout << "\n";

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);	
	
	int tt;
	cin >> tt;
	while(tt--){
		int n;
		cin >> n;
		vector<ll> a(n),b(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
		}
		ll x = *min_element(all(a));
		ll y = *min_element(all(b));
		ll ans = 0ll;
		for (int i = 0; i < n; i++)
		{
			ll p = (a[i] - x);
			ll q = (b[i] - y);
			ans += max(p,q);
		}
		cout << ans << "\n";
	}
	
	return 0;
}
