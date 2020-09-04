#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << "\n";
#define debv(v) for (auto usb: v) cout << usb << " "; cout << "\n";

// n == (1 \/ 0) ????, memory?

bool is(ll x, ll a, ll b){
	return x >= a && x < b;
}

void solve(){
	ll n,x,y;
	cin >> n >> x >> y;
	ll k = y-x;
	vector<ll> div;
	
	for (int i = 1; i <= k; i++)
		if(k % i == 0) div.push_back(i);
	
	ll mn = 1e18;
	
	for(int i = 1; i<=x; i++){
		for(ll d: div){
			if((x-i) % d == 0 && (y-i) % d == 0 && is((x-i) / d, 0, n) && is((y-i) / d, 0, n)){
				mn = min(mn, i + d * (n-1));
			}
		}
	}
	
	for(int i = 1; i<=x; i++){
		for(ll d: div){
			if((x-i) % d == 0 && (y-i) % d == 0 && is((x-i) / d, 0, n) && is((y-i) / d, 0, n) && mn == i + d*(n-1)){
				for (int j = 0; j < n; j++)
					cout << i + d*j << " ";
				cout << "\n";
				return;
			}
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(20);	

	int t = 1;
	cin >> t;

	while(t--) solve();
	//cout << "OK\n";
	
	return 0;
}
