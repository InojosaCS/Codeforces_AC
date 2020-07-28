#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;
#define debv(v) for (int i = 0; i < sz(a); i++) cout << v[i] << " "; cout << "\n";

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);

	ll n;
	cin >> n;
	while(n--){
		ll c,k;
		cin >> c >> k;
		vector<int> a(c, k/c);
		for (int i = 0; i < k%c; i++)
			a[i]++;
		ll sum = 0ll;
		for (int i = 0; i < c; i++)
			sum	+= (a[i]*a[i]);
		
		cout << sum << "\n";
	}
	return 0;
}
