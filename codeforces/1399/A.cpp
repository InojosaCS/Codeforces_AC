#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;
#define debv(v) for (auto x: v) cout << x << " "; cout << "\n";

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);	
	
	int tt;
	cin >> tt;
	while(tt--){
		int n;
		cin >> n;
		vector<ll> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(all(a));
		string ans = "YES\n";
		for (int i = 1; i < n; i++)
		{
			if(a[i] - a[i-1] > 1){
				ans = "NO\n";
			}
		}
		cout << ans;
	}
	
	return 0;
}
