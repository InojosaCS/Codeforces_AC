#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << "\n";
#define debv(v) for (auto usb: v) cout << usb << " "; cout << "\n";

// n == (1 \/ 0) ????, memory?

void solve(){
	ll n;
	cin >> n;
	vector<ll> a(n);
	vector<ll> copy(n);
	
	for (int i = 0; i < n; i++){
		cin >> a[i];
		copy[i] = a[i];
	}
	
	if(n == 1){
		cout << "1 1\n";
		cout << -a[0] << "\n";
		cout << "1 1\n";
		cout << a[0] << "\n";
		cout << "1 1\n";
		cout << -a[0] << "\n";
		return;
	}
	
	// First
	cout << "1 " << n-1 << "\n";
	
	for (int i = 0; i + 1 < n; i++){
		cout << copy[i] * (n-1) << " ";
		a[i] += copy[i]*(n-1);
	}
	
	// Second
	cout << "\n" << 2 << " " << n << "\n";
	
	for (int i = 0; i + 2 < n; i++)
		cout << 0 << " ";
		
	cout << copy[n-1] * (n-1) << "\n";
	a[n-1] += copy[n-1]*(n-1);
	
	// third
	cout << "1 " << n << "\n";
	
	for (int i = 0; i < n; i++){
		cout << -1LL * n * copy[i] << " ";
		a[i] += -1LL * n * copy[i];
	}
	
	for (int i = 0; i < n; i++)
		assert(a[i] == 0);
	
	cout << "\n";
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
