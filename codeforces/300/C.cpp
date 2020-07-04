#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
 
#define for0(i,n) for(int i=0; i<(int)n; i++)
#define forn(i,n) for(int i=1; i<=(int)n; i++)
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define sz(s) (ll) s.size()
#define endl cout << "\n";
#define deb(i) cout << "Aqui " << (ld) i << "\n";
//#define int long long 

ll mod = (ll) (1e9+7), mx = (ll) (1e6+7), a, b, n;
vll fact(mx, 1ll);

ll expo(ll x, ll y){
	if(y==0) return 1ll;	
	if(y==1) return x%mod;
	return (expo((x*x)%mod, y/2ll)*((y%2ll)?x:1ll))%mod;
}

ll modInverse(ll k) 
{ 
    return expo(k, mod - 2); 
}
 
void getFact(){
	for(ll i=1ll; i<mx;i++){
		fact[i] = (fact[i-1]*i)%mod;
	}
}

bool check(ll k){
	while(k){
		ll p = k%10ll;
		if(p!=a && p!=b)
			return false;
		k /= 10ll;
	}
	return true;
}

void solve(){
	cin >> a >> b >> n;
	
	getFact();
	
	ll sum  = 0ll;
	
	for(ll i=0ll; i<=n; i++){
		ll current = i*a + (n-i)*b;
		//cout << current << "\n";
		if(check(current)){
			sum = (sum + (((fact[n] * modInverse(fact[i]))%mod) * modInverse(fact[n-i]))%mod)%mod;
		}
	}
	
	cout << sum << "\n";
}
int main(){
	//auto T=clock();
	//cout<<double(clock()-T)/CLOCKS_PER_SEC<<'\n';
	
	solve();
	
	return 0; 
}
