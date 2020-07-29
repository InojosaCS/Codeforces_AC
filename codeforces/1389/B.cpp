#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;
#define debv(v) for (int i = 0; i < sz(v); i++) cout << v[i] << " "; cout << "\n";

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);

	int tt;
	cin >> tt;
	while(tt--){
		ll n,k,z;
		cin >> n >> k >> z;
		vector<ll> a(n+1,0ll),p(n+1,0ll),prefix(n+1,0ll),ans;
		for(int i=0; i<n; i++) cin >> a[i+1];
		ll mx = 0;
		for(int i=1; i<=n; i++){
			prefix[i] = prefix[i-1] + a[i];
			if(a[i]+a[i-1]>mx) mx = a[i]+a[i-1];
			p[i] = mx;
		}
		ans.push_back(prefix[k+1]);
		for (int i = 2; i <= n; i++)
		{
			for (ll j = 1ll; j<=z && (i-1)+j+(j-1)<=k ; j+=1ll)
			{
				ll current = prefix[i];
				current += (a[i-1]*j + a[i]*(j-1ll));
				current += (prefix[(i-1)+k-((i-1)+j+(j-1))] - prefix[i-1]);
				//deb(prefix[i]); 
				//cout << "i: " << i << " j: " << j << " diff: " << (i-1)+k-(i-1)+j+(j-1) << "\n";
				ans.push_back(current);
			}
			
		}
		cout << *max_element(all(ans)) << "\n";
	}
	
	return 0;
}
