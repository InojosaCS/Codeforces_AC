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
		ll a,b;
		cin >> a >> b;
		ll x = max(a,b), y = min(a,b);
		if(x<=2ll*y && (a+b)%3==0) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
