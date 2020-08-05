#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;
#define debv(v) for (auto x: v) cout << x << " "; cout << "\n";

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);	
	
	ll t;
	cin >> t;
	while(t--){
		ll x,y,n;
		cin >> x >> y >> n;
		ll k = n/x;
		if(k*x + y <= n){
			cout << k*x+y << "\n";
		}else{
			cout << (k-1ll)*x + y << "\n";
		}
	}
	return 0;
}
