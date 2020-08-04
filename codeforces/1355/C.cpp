#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;
#define debv(v) for (auto x: v) cout << x << " "; cout << "\n";

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);	
	
	ll a,b,c,d;
	cin >> a >> b >> c >> d;
	ll ans = 0ll, a2 = 0ll;
	
	for (ll i = a; i <= b; i++)
	{
		ll x1 = b + i;
		ll x2 = c + i;
		// Outside D
		ll q1 = (d - c + 1ll) * (max(x2, d) - d);
		ll q2 = (d - c + 1ll) * (max(x1, d + 1ll) - d - 1ll);
		// Out
		ll out = q1 - q2;
		// inside C and D
		ll p1 = min(x2, d) - c;
		ll p2 = max(0ll, min(x1, d+1ll) - c - 1ll);
		// In
		ll in = p1 * (p1 + 1ll) / 2ll - p2 * (p2 + 1ll) / 2ll;
		ll s = out + in; 
		// deb(out); deb(in);
		// cout << "p1: " << p1 << " * p2: " << p2 << " ||| " << "in " << in << " ** out: " << out << " ||| ";
		ans += s;
		//for(int j = b; j <= c; j++){
			//for(int k = c; k <= d; k++){
				//if(i+j<=k) break;
				//a2++;
			//}
		//}
		//if(a2 != ans){
			//cout << i << " " << " diff " << a2 << " " << ans << "\n";
		//}
	}
	
	cout << ans << "\n";
	return 0;
}
