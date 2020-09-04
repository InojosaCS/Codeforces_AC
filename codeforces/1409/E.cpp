#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << "\n";
#define debv(v) for (auto usb: v) cout << usb << " "; cout << "\n";

// n == (1 \/ 0) ????, memory?

vector<ll> y(200123);
ll x[200123];
	
int lookG(ll r, ll p){
	ll l = 0;
	ll ans = -1;
	while(l<=r){
		ll mid = (l+r) / 2;
		if(x[mid] <= p){
			l = mid + 1;
			ans = mid;
		}else{
			r = mid - 1;
		}
	}
	return ans;
}

int lookL(ll r, ll p){
	ll l = 0;
	ll ans = -1;
	while(l<=r){
		ll mid = (l+r) / 2;
		if(x[mid] >= p){
			r = mid - 1;
			ans = mid;
		}else{
			l = mid + 1;
		}
	}
	return ans;
}


void solve(){
	ll n,k;
	cin >> n >> k;
	
	for (int i = 0; i < n; i++)
		cin >> x[i];
	
	for (int i = 0; i < n; i++)
		cin >> y[i];
	
	sort(x, x+n);
	
	vector<pair<ll,ll>> lb(n), rb(n);
	vector<int> prefixStart(n, 1), prefixLast(n,1);
	
	for (int i = 0; i < n; i++)
	{
		rb[i] = {i, lookG(n-1, x[i] + k)};
		lb[i] = {lookL(n-1, x[i] - k), i};
		int r1 = rb[i].first, r2 = rb[i].second;
		int l1 = lb[i].first, l2 = lb[i].second;
		prefixStart[r1] = max(prefixStart[r1], r2 - r1 + 1);
		prefixStart[l1] = max(prefixStart[l1], l2 - l1 + 1);
		prefixLast[r2] = max(prefixLast[r2], r2 - r1 + 1);
		prefixLast[l2] = max(prefixLast[l2], l2 - l1 + 1);
		//cout << l1 << " " << l2 << "\n";
		//cout << r1 << " " << r2 << " ***\n";
	}
	
	int ans = 1;
	int mx1 = 1, mx2 = 1;
	
	for (int i = 0; i < n; i++)
	{
		mx2 = max(mx2, prefixLast[i]);
		prefixLast[i] = mx2;
		//cout << i << ": " << prefixStart[i] << "\n";
		//cout << i << ": " << prefixLast[i] << " *** \n";
	}
	
	for (int i = n - 1; i >= 0; i--)
	{
		mx1 = max(mx1, prefixStart[i]);
		prefixStart[i] = mx1;
	}
	
	for (int i = 0; i < n; i++)
	{
		int r1 = rb[i].first, r2 = rb[i].second;
		int l1 = lb[i].first, l2 = lb[i].second;
		
		// left 
		int helper1 = (r1 == 0) ? 0 : prefixLast[r1 - 1];
		int helper2 = (r2 == n-1) ? 0 : prefixStart[r2 + 1];
		int temp1 = r2 - r1 + 1 + helper1;
		int temp2 = r2 - r1 + 1 + helper2;
		
		// right
		int helper3 = (l1 == 0) ? 0 : prefixLast[l1 - 1];
		int helper4 = (l2 == n-1) ? 0 : prefixStart[l2 + 1];
		int temp3 = l2 - l1 + 1 + helper3;
		int temp4 = l2 - l1 + 1 + helper4;
		
		ans = max({ans, temp1, temp2, temp3, temp4});
	}
	
	cout << ans << "\n";

	for (int i = 0; i < n; i++)
		x[i] = 1e18;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(20);	

	for (int i = 0; i < 100123; i++)
		x[i] = 1e18;
		
	int t = 1;
	cin >> t;

	while(t--) solve();
	//cout << "OK\n";
	
	return 0;
}
