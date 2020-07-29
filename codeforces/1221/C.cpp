#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;
#define debv(v) for (int i = 0; i < sz(a); i++) cout << v[i] << " "; cout << "\n";

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);

	int q;
	cin >> q;
	while(q--){
		ll c,m,x;
		cin >> c >> m >> x;
		ll k = (c+m+x)/3ll;
		cout << min({c,m,k}) << "\n";
	}
	
	return 0;
}
