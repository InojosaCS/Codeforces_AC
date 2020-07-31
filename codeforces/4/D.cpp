#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;
#define debv(v) for (int i = 0; i < sz(v); i++) cout << v[i] << " "; cout << "\n";

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);	
	
	ll n,w,h;
	cin >> n >> w >> h;
	vector<tuple<ll,ll,ll> > envelopes;
	
	for (int i = 0; i < n; i++)
	{
		ll a,b;
		cin >> a >> b;
		envelopes.push_back({a,b,i+1});
	}
	
	sort(all(envelopes));
	vector<ll> dp(n,1ll), parent(n+7,-1ll);
	
	for (int i = 0; i < n; i++)
	{
		ll x,y,z;
		tie(x,y,z) = envelopes[i];
		if(x > w && y > h) dp[i] = 1ll;
		else dp[i] = 0ll;
	}
	
	for (int i = 0; i < n; i++)
	{
		ll x1,y1,z1;
		tie(x1,y1,z1) = envelopes[i];
		for (int j = 0; j < i; j++)
		{
			ll x2,y2,z2;
			tie(x2,y2,z2) = envelopes[j];
			if(x2 > w && y2 > h && x1 > x2 && y1 > y2 && dp[j] + 1ll > dp[i]){
				dp[i] = dp[j] + 1ll;
				parent[z1] = z2;
			}
		}
	}
	ll mx = *max_element(all(dp));
	
	cout << mx << "\n";
	vector<ll> ans;
	
	for (int i = n-1; i >= 0; i--)
	{
		if(dp[i] == mx && mx){
			ll x,y,z;
			tie(x,y,z) = envelopes[i];
			ans.push_back(z);
			ll k = z;
			while(parent[k] != -1){
				ans.push_back(parent[k]);
				k = parent[k];
			}
			break;
		}
	}
	reverse(all(ans));
	
	for(ll a: ans) cout << a << " ";
	cout << "\n";
	return 0;
}
