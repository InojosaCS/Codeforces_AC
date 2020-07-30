#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl
#define debv(v) for (int i = 0; i < sz(a); i++) cout << v[i] << " "; cout << "\n";

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);
	
	int tt;
	cin >> tt;
	while(tt--){
		ll n;
		cin >> n;
		if(n>=31){
			ll k = n - (6+10+14);
			if(k == 6 || k == 10 || k == 14){
				cout << "YES\n" << "6 10 15 " << k-1 << "\n";
			}else{
				cout << "YES\n" << "6 10 14 " << k << "\n";
			}
		}else{
			cout << "NO\n";
		}
	}
	return 0;
}
