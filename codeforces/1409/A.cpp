#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << "\n";
#define debv(v) for (auto usb: v) cout << usb << " "; cout << "\n";

// n == (1 \/ 0) ????, memory?

void solve(){
	ll a,b;
	cin >> a >> b;
	ll x = abs(a-b) / 10 + (abs(a-b) % 10 != 0);
	cout << x << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(20);	

	int t = 1;
	cin >> t;

	while(t--) solve();
	//cout << "0K\n";
	
	return 0;
}
