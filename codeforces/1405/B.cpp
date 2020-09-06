#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << "\n";
#define debv(v) for (auto usb: v) cout << usb << " "; cout << "\n";

// n == (1 \/ 0) ????, memory?

void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	ll goal = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(a[i] > 0) goal +=a[i];
	}
	
	ll base = 0, free = 0;
	
	for (int i = n-1; i > -1; i--)
	{
		if(a[i] <= 0){
			base += -a[i];
		} else {
			if(a[i] >= base){
				free += base;
				base = 0LL;
			}
			else{
				base = base - a[i];
				free += a[i];
			}
		}
	}
	
	cout << goal - free << "\n";
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
