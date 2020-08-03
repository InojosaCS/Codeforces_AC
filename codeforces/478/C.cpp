#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;
#define debv(v) for (auto x: v) cout << x << " "; cout << "\n";

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);	
	
	ll a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a,a+3);
	
	cout << min(a[0] + a[1], (a[0]+a[1]+a[2])/3ll) << "\n";
	return 0;
}
