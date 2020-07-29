#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;
#define debv(v) for (int i = 0; i < sz(a); i++) cout << v[i] << " "; cout << "\n";

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);

	ll n;
	cin >> n;
	while(n--){
		ll r,b,k;
		cin >> r >> b >> k;
		ll x = max(r,b), y = min(r,b);
		ll mcm = (x*y)/__gcd(x,y), m = x%y;
		ll c = (m==0) ? 0ll : max(y - y % m, y - (mcm/x - 1ll)*m);
		if(c == y) c = y - m;
		// cout << x << " " << y << " " << c << "\n";
		if(y * k < x + c) cout << "REBEL\n";
		else cout << "OBEY\n";
	}
	return 0;
}
