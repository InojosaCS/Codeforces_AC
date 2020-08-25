#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << "\n";
#define debv(v) for (auto usb: v) cout << usb << " "; cout << "\n";

// n == (1 \/ 0) ????, memory?

void solve(){
	ll x1,y1,z1;
	ll x2,y2,z2;
	cin >> x1 >> y1 >> z1;
	cin >> x2 >> y2 >> z2;
	
	ll sum = 0;
	
	// the 3s
	ll k = min(z1,y2);
	z1 -= k;
	y2 -= k;
	sum += 2LL * k;
	
	sum -= 2LL * max(0LL, z2 - (x1 + z1));
	cout << sum << "\n";
	
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
