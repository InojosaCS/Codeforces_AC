#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << "\n";
#define debv(v) for (auto usb: v) cout << usb << " "; cout << "\n";

// n == (1 \/ 0) ????, memory?

void solve(){

	string s;
	int x;
	cin >> x >> s;
	for (int i = 0; i < sz(s); i+=2) cout << s[i];
	cout << "\n";
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
