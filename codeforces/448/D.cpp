#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;
#define debv(v) for (auto x: v) cout << x << " "; cout << "\n";

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);	

	ll n,m,k;
	cin >> n >> m >> k;
	ll l = 1ll, r = n*m, ans = 1ll;
	while(l<=r){
		ll mid = (l + r) / 2ll;
		ll x = 0ll;
		for (ll i = 1ll; i <= n; i+=1ll) x += min(m, (mid-1ll)/i);
		if(x < k){
			l = mid + 1ll;
			ans = mid;
		}else{
			r = mid - 1ll;
		}
	}
	cout << ans << "\n";
	return 0;
}
