#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl
//#define int long long



int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);

	int tt;
	cin >> tt;
	while(tt--){
		ll n,m;
		cin >> n >> m;
		ll a[n], b[m];
		map<ll,ll> pos;
		
		for(ll i = 0ll; i < n; i++){
			cin >> a[i];
			pos[a[i]] = i;
		}
		
		for(ll i = 0ll; i < m; i++){
			cin >> b[i];
		}
		
		ll mn = 0, ans = 0ll;
		for (ll i = 0ll; i < m; i++)
		{
			if(pos[b[i]] > mn){
				ans += ((pos[b[i]]-i)*2ll + 1ll);
				mn = pos[b[i]];
			}else{
				ans++;
			}
		}
		cout << ans << "\n";
	}
    return 0;
}
