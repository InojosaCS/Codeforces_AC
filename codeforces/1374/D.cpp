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
		ll n,k;
		cin >> n >> k;
		ll a[n];
		set<ll> s;
		map<ll,ll> m;
		
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if(a[i]%k){
				ll x = (a[i] - 1ll) / k;
				x = (x + 1ll) * k - a[i];
				//cout << i << ": "<< x << " | ";
				if(s.count(x)){
					s.insert(m[x] + k);
					m[x] = m[x] + k;
				}else{
					s.insert(x);
					m[x] = x;
				}
			}
		}
		
		ll cnt = 0ll, ans = 0ll;
		for(ll diff: s){
			ans += (diff - (cnt-1ll));
			cnt = diff + 1;
		}
		cout << ans << "\n";
	}
	return 0;
}
