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
	ll a,b,x,y,n;
	cin >> a >> b >> x >> y >> n;
	
	// result 1
	ll q = max(a-n, x);
	ll w = n - (a - q);
	ll e = max(b-w, y);
	
	// result 2
	ll q2 = max(b-n, y);
	ll w2 = n - (b - q2);
	ll e2 = max(a-w2, x);
	
	cout << min(q*e, q2*e2) << "\n";
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
