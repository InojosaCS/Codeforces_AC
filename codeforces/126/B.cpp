#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<long long> vll;
typedef vector<bool> vb;

#define pb push_back
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define sz(s) (ll) s.size()
#define deb(i) cout << "Aqui " << (ld) i << "\n";

vll Hash(1e6+7,0ll);
vll ppow(1e6+7,1ll);
ll mod = (ll) (1e9+9), p = 31ll;

void Hashing(string s){
	
	for (int i = 1; i < 1e6+7; i++)
	{
		ppow[i] = (ppow[i-1] * p) % mod;
	}
	
	for (int i = 0; i < sz(s); i++)
	{
		Hash[i+1] = (Hash[i] + (s[i]-'a'+ 1) * ppow[i])%mod;
	}
	
}

int main(){
	
	string s;
	cin >> s;
	int n = sz(s);
	Hashing(s);
	vll looking, index, adj;
	bool ans = false;
	
	for(int i=1; i<n-1; i++){
		if((Hash[i]*ppow[n-i])%mod == (Hash[n]-Hash[n-i]+mod)%mod){
			ll a,b,c;
			a = i; 
			b = (Hash[i]*ppow[n-i])%mod;
			c = n-i;
			index.pb(a);
			looking.pb(b);
			adj.pb(c);
			
		}
	}
	
	ll talla;
	
	for(int k=sz(looking)-1; k>-1 && !ans; k--){	
		for(int i=1; i+index[k]<n; i++){
			if(((Hash[i+index[k]]-Hash[i]+mod)*ppow[adj[k]-i])%mod == looking[k]){ 
				ans = true;
				talla = index[k];
				break;
			}
		}
	}
	
	if(ans){
		for(int i=0; i<talla;i++){
			cout << s[i];
		}
		cout << "\n";
	}else{
		cout << "Just a legend\n";
	}
	
	return 0;
}
