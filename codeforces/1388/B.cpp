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
		ll k = n/4 + (n%4!=0);
		for (int i = 0; i < n-k; i++)
		{
			cout << '9';
		}
		
		for (int i = 0; i < k; i++)
			cout << '8';
		cout << "\n";
	}
	return 0;
}
