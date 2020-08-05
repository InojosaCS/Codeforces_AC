#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;
#define debv(v) for (auto x: v) cout << x << " "; cout << "\n";

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);	
	
	ll n,k;
	cin >> n >> k;
	vector<ll> both, bob, alice;
	
	for (int i = 0; i < n; i++)
	{
		ll t,a,b;
		cin >> t >> a >> b;
		if(a && b) both.push_back(t);
		else if (a) alice.push_back(t);
		else if (b) bob.push_back(t);
	}
	
	if(sz(alice) + sz(both) < k || sz(bob) + sz(both) < k){
		cout << "-1\n";
		return 0;
	}
	
	sort(all(alice));
	sort(all(bob));
	sort(all(both));
	
	vector<ll> p0(n+7, (ll) 1e10),p1(n+7, (ll) 1e10),p2(n+7, (ll) 1e10);
	p0[0] = p1[0] = p2[0] = 0;
	
	for (int i = 1; i <= sz(both); i++) p0[i] = p0[i-1] + both[i-1];
	for (int i = 1; i <= sz(alice); i++) p1[i] = p1[i-1] + alice[i-1];
	for (int i = 1; i <= sz(bob); i++) p2[i] = p2[i-1] + bob[i-1];
	
	ll ans = (ll)(1e18);
	
	for(int i = 0; i<=k; i++){
		ans = min(ans, p1[i] + p2[i] + p0[k-i]);
	}
	cout << ans << "\n";
	return 0;
}
