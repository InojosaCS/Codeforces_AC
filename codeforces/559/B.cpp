#include <bits/stdc++.h>
 
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (long long) x.size()

long long N = 2*(1e5)+8, mod = (long long) (1e9+9), p = 31ll;
vector<long long> ahash(N, 0ll), bhash(N, 0ll), ppow(N, 1ll);
bool ans = false;

void hashing(string a, string b){
	int n = sz(a);

	for (int i = 1; i < n+7; ++i)
		ppow[i] = (ppow[i-1]*p)%mod;
	
	for (int i = 0; i < n; ++i)
	{
		ahash[i+1] = (ahash[i] + (a[i]-'a'+1)*ppow[i])%mod;
		bhash[i+1] = (bhash[i] + (b[i]-'a'+1)*ppow[i])%mod; 
	}
}

string x,y;

bool dp(int la, int ra, int lb, int rb){
	int mida = (ra+la)/2;
	int midb = (rb+lb)/2;
	// cout << la << " " << ra << " " << mida << "\n";
	// cout << lb << " " << rb << " " << midb << "\n";
	
	// for(int i = la; i<=ra; i++){
	// 	cout << x[i-1];
	// }
	// cout << "\n";

	// for(int i = lb; i<=rb; i++){
	// 	cout << y[i-1];
	// }
	// cout << "\n";

	if(la==ra){
		return x[la-1]==y[lb-1];
	}
	
	
	int exp = max(la,lb)-min(la,lb);
	long long a,b;

	if(la<lb){
		a = (((ahash[ra]-ahash[la-1]+mod)%mod)*ppow[exp])%mod;
		b = (bhash[rb]-bhash[lb-1]+mod)%mod;
	}else{
		a = (ahash[ra]-ahash[la-1]+mod)%mod;
		b = (((bhash[rb]-bhash[lb-1]+mod)%mod)*ppow[exp])%mod;
	}
	
	// cout << a << " " << b << "\n";
	
	if(a==b){
		return true;
	}

	if((ra-la+1)%2){
		return false;
	}

	return  ((dp(la, mida, midb+1, rb) && dp(mida+1, ra, lb, midb)) ||
		(dp(la, mida, lb, midb) && dp(mida+1, ra, midb+1, rb)));
}

int main(){
	
	
	string a,b;
	cin >> a >> b;
	x = a;
	y = b;
	hashing(a,b);
	ans = dp(1, sz(a),1,sz(b));
	cout << (ans ? "YES\n" : "NO\n");

	return 0;
}
