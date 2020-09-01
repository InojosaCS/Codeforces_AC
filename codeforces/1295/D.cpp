#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << "\n";
#define debv(v) for (auto usb: v) cout << usb << " "; cout << "\n";

// n == (1 \/ 0) ????, memory?

ll get (ll n, ll r) {
    vector<ll> p;
    for (ll i=2; i*i<=n; ++i)
        if (n % i == 0) {
            p.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        p.push_back (n);

    ll sum = 0LL;
    for (ll msk=1; msk<(1<<p.size()); ++msk) {
        ll mult = 1LL,
            bits = 0LL;
        for (ll i=0; i<(ll)p.size(); ++i)
            if (msk & (1<<i)) {
                ++bits;
                mult *= p[i];
            }

        ll cur = r / mult;
        if (bits % 2 == 1)
            sum += cur;
        else
            sum -= cur;
    }

    return r - sum;
}

void solve(){
	ll a,m;
	cin >> a >> m;
	ll k = __gcd(a, m);
	ll q = m / k;
	ll p = 	a / k;
	
	ll x = get(q, p-1);
	ll y = get(q, p+q);

	cout << y-x-1 << "\n";
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
