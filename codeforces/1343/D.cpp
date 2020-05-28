#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
typedef vector<ii> vii;

#define solve imAwesome
#define for0(i,n) for(int i=0; i<(int)n; i++)
#define forn(i,n) for(int i=1; i<=(int)n; i++)
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define all(x) x.begin(),x.end()
#define endl cout << "\n";
#define debug cout << "Aqui\n";
#define deb(i) cout << "Aqui " << (ll) i << "\n";
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	ll t;
	cin >> t;
	while(t--){
		ll n,k;
		cin >> n >> k;
		vll a(n), sums(2*k+5,0), pref(2*k+5,0);
		for0(i,n) cin >> a[i];
		
		for (int i = 0; i < n/2; i++)
		{	
			sums[a[i]+a[n-i-1]]++;
			ll mx = max(a[i],a[n-i-1])+k;
			ll mn = min(a[i],a[n-i-1]);
			pref[mx+1]--;
			pref[mn+1]++;
		}
		
		for (int i = 1; i < 2*k+5; i++) pref[i]+=pref[i-1];
		ll ans = 1e18;
		for (int i = 2; i < 2*k+5; i++){
			ans = min(ans, 2*(n/2-pref[i]) + (pref[i]-sums[i]));
		}	
		
		cout << ans << "\n";
	}
	
	return 0;

}
