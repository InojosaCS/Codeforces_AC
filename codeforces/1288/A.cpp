#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);

	int tt;
	cin >> tt;
	while(tt--){
		ll n,d;
		cin >> n >> d;
		string ans = "NO\n";
		
		for (ll i = 1; i*i <= d && i <= n; i++)
		{
			if(d<=n || i + d / (i + 1ll) + (d%(i+1) != 0) <= n){
				ans = "YES\n";
			}
		}
		
		cout << ans;
	}

	return 0;
}
