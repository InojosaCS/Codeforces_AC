#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
 
#define solve imAwesome
#define for0(i,n) for(int i=0; i<(int)n; i++)
#define forn(i,n) for(int i=1; i<=(int)n; i++)
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define all(x) x.begin(),x.end()
#define sz(s) (ll) s.size()
#define endl cout << "\n";
#define deb(i) cout << "Aqui " << (ld) i << "\n";
#define pi 3.141592653589793238462643383279502884197169399375105820974944592307816406286L
//#define int long long 
 
const int mx = 1e7+7;
vector<bool> prime(mx,true);
vector<int> primes;

void sieve(){
	for(int i=4; i<mx; i+=2)
		prime[i]=false;
		
	for(int i=3; i<mx; i+=2){
		if(prime[i]){
			for(int j=2*i; j<mx; j+=i){
				prime[j]=false;
			}
		}
	}
	primes.pb(2);
	for (int i = 3; i < mx; i+=2)
		if(prime[i])
			primes.pb(i);
		
}
 
int main(){
	//auto T=clock();
	
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.precision(20);
	sieve();
	int n;
	cin >> n;
	vector<pair<int,int>> ans;
		
	for (int k = 0; k < n; k++)
	{
		int a,x=-1,y=-1;
		cin >> a;
		vi auxiliar;
	
		for(auto p: primes){
			if(p*p>a)
				break;
			if(a%p==0)		
				auxiliar.pb(p);
			while(a%p==0)		
				a/=p;
		}
		
		if(a>1)
			auxiliar.pb(a);
		
		if(sz(auxiliar)>1){
			x = auxiliar[0];
			y = 1;
			for (int i = 1; i < sz(auxiliar); i++)
				y *= auxiliar[i];
		}	
		ans.pb({x,y});
	}
	
	for(auto x: ans)
		cout << x.f << " ";
	endl
	
	for(auto x: ans)
		cout << x.s << " ";
	endl
	
	//cout<<double(clock()-T)/CLOCKS_PER_SEC<<'\n';
	return 0;
 
}
