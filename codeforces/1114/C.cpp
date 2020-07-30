#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;
#define debv(v) for (int i = 0; i < sz(v); i++) cout << v[i] << " "; cout << "\n";



int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);	
	
	ll n,b;
	cin >> n >> b;
	vector<pair<ll,ll>> div;
	for (ll i = 2ll; i*i <= b; i++)
	{
		ll k = 0ll;
		while(b%i == 0){
			b /= i;
			k += 1ll;
		}
		if(k) div.push_back({i,k});
	}
	
	if(b>1) div.push_back({b,1ll});
	ll ans = (ll) 1e18+7;
	
	for(auto x: div){
		ll sum = 0ll;
		ll k = (ll) x.first;
		//deb(x.first); deb(x.second);
		while(k <= n){
			sum += (n/k);
			if(k <= n/x.first) k *= (ll) x.first;
			else break;
		}
		sum /= (ll) x.second;
		ans = min(ans, sum);
	}
	cout << ans << "\n";
	return 0;
}
