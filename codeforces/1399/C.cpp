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
		vector<ll> cnt(300,0ll);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			cnt[a[i]]++;
		}
		
		ll ans = 0ll;
		
		for (int s = 101; s >= 0; s--)
		{
			vector<ll> aux = cnt;
			ll temp = 0;
			for (int i = 0; i < n; i++)
			{
				if(s - a[i] == a[i] && aux[a[i]]<=1){
					continue;
				}
				if(s-a[i]>0 && aux[s - a[i]] && aux[a[i]]){
					temp++;
					aux[s - a[i]]--;
					aux[a[i]]--;
				}
			}
			ans = max(ans, temp);
		}
		cout << ans << "\n";
	}
	
	return 0;
}
