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

	long long n, m;
	cin >> n >> m;
	
	if(n==2){
		cout << "0\n";
		return 0;
	}
	
	ll a,b,c;
	a = b = c = 1ll;
	
	for (ll i = 1ll; i <= m; i++)
		a = a*i%M;
	
	for (ll i = 1ll; i <= m-(n-1); i++)
		c = c*i%M;
	
	for (ll i = 1ll; i <= n-1; i++)
		b = b*i%M;
		
	b = inverseM(b);
	c = inverseM(c);
	
	cout << ((((a*b)%M)*c%M)*(n-2ll)%M)*expo(2, n-3ll)%M << "\n";

	return 0;
}
