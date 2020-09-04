#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << "\n";
#define debv(v) for (auto usb: v) cout << usb << " "; cout << "\n";

// n == (1 \/ 0) ????, memory?

void solve(){
	ll n,m,p;
	cin >> n >> m >> p;

	ll l = -1,r = -1;
	
	for (int i = 0; i < n; i++)
	{
		int ai;
		cin >> ai;
		if(ai % p && l < 0){
			l = i;
		}
	}
	
	for (int i = 0; i < m; i++)
	{
		int ai;
		cin >> ai;
		if(ai % p && r < 0){
			r = i;
		}
	}
	
	cout << l+r << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(20);	

	int t = 1;
	//cin >> t;

	while(t--) solve();
	//cout << "OK\n";
	
	return 0;
}
