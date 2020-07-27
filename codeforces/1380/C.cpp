#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;

const long long M = 998244353ll;
	
ll expo(ll a, ll b){
	if(b==0) return 1ll;
	if(b==1) return a%M;
	else return expo(a*a%M, b/2)*(b%2 ? a : 1ll)%M;
}

ll inverseM(ll a){
	return expo(a, M-2);
}


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);

	int t;
	cin >> t;
	while(t--){
		ll n,x;
		cin >> n >> x;
		vector<ll> a(n);
		for(int i=0; i<n; i++) cin >> a[i];
		sort(all(a));
		ll ans = 0ll, last = n;
		
		for(ll i = n - 1; i > -1; i--){
			if(a[i]*(last - i) >= x){
				ans++;
				last = i;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}
