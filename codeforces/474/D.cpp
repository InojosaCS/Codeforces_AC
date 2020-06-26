#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
 
#define solve imAwesome
#define for0(i,n) for(int i=0; i<(int)n; i++)
#define forn(i,n) for(int i=1; i<=(int)n; i++)
#define pb push_back
#define f first
#define s second
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define all(x) x.begin(),x.end()
#define sz(s) (ll) s.size()
#define endl cout << "\n";
#define deb(i) cout << "Aqui " << (ld) i << "\n";
//#define int long long 

int32_t main(){
	
	ll t,k,mod =(ll)(1e9+7ll),mx=1e5+7;
	cin >> t >> k;
	vll prefix(mx,1ll),pSum(mx,0ll);
	
	for (ll i = k; i < mx; i++)
		prefix[i] = ((prefix[i-1]%mod) + ((prefix[i-k])%mod))%mod;
	 
	for (int i = 1; i < mx; i++)
		pSum[i] = ((pSum[i-1]%mod)+(prefix[i]%mod))%mod;

	
	while(t--){
		ll a,b;
		cin >> a >> b;
		cout << (mod + (pSum[b]%mod)-(pSum[a-1]%mod))%mod << "\n";
		}
	return 0;
	
}
//1 48096
//95515 99613
