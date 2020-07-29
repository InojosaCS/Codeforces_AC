#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;

#define all(	x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;
#define debv(v) for (int i = 0; i < sz(v); i++) cout << v[i] << " "; cout << "\n";

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);

	int tt;
	cin >> tt;
	while(tt--){
		ll n;
		cin >> n;
		vector<ll> a(n), left(n,0), right(n,0);
		
		for(int i=0; i<n;i++) cin >> a[i];
			
		vector<bool> v1(n+7,false), v2(n+7,false);
		ll mx1 = 1, mx2 = 1;
		
		for (int i = 0; i < n; i++)
		{
			v1[a[i]] = true;
			while(v1[mx1]) mx1++;
			left[i] = mx1-1ll;
			v2[a[n-(i+1)]] = true;
			while(v2[mx2]) mx2++;
			right[n-(i+1)] = mx2-1ll;
		}
		vector<pair<int,int>> ans;
		
		for (int i = 0; i < n-1; i++)
		{
			if(left[i] == (i+1) && right[i+1] == (n-(i+1)))
				ans.push_back({i+1, n-(i+1)});
		}
		
		cout << sz(ans) << "\n";
		for(auto p : ans) cout << p.first << " " << p.second << "\n";
		
	}
	
	return 0;
}
