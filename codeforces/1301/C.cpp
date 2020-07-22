#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);
	
	int t;
	cin >> t;
	
	while(t--){
		ll n, m;
		cin >> n >> m;
		// Hell of math
		ll z = n - m;
		ll p = z / (m + 1ll);
		ll r = z % (m + 1ll);
		ll l = m - r;
		ll k = z - r * (p + 1ll);
		ll sum1 = m * n - m * (m - 1ll) / 2ll; 
		ll sum2 = (p + 1ll) * (z * r - (p + 1ll) * r * (r + 1ll) / 2ll);
		ll sum3 = l * k * p - p * p * l * (l + 1ll) / 2ll;
		// deb(z); deb(p); deb(r); deb(l); deb(k); deb(sum1); deb(sum2); deb(sum3);
 		cout << sum1 + sum2 + sum3 << "\n";
	}
	return 0;
}
