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
		ll n;
		cin >> n;
		ll a = 0ll, b = 0ll;
		while(n % 2ll == 0){
			n /= 2ll;
			a++;
		}
		 
		while(n % 3ll == 0){
			n /= 3ll;
			b++;
		}
		if(b >= a && n == 1){
			cout << 2ll * b - a << "\n";
		}else{
			cout << "-1\n";
		}
	}
	return 0;
}
