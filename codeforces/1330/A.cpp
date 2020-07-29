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
		ll n, x;
		cin >> n >> x;
		vector<ll> a(n);
		vector<bool> visited(210,false);
		
		for(int i=0; i<n;i++){
			cin >> a[i];
			visited[a[i]] = true;
		}
		
		for(int i=1; i<210; i++){
			if(!visited[i] && x){
				visited[i] = true;
				--x;
			}
		}
		
		for (int i = 1; i < 210; i++)
		{
			if(!visited[i]){
				cout << i-1 << "\n";
				break;
			}
		}	
	}
	
	return 0;
}
