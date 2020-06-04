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
#define deb(i) cout << "Aqui " << (ld) i << "\n";
#define pi 3.141592653589793238462643383279502884197169399375105820974944592307816406286L
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	//auto T=clock();
	ll t;
	cin >> t;
	while(t--){
		ll n,x;
		cin >> n >> x;
		vll d(n+1,0ll);
		for0(i,n-1){
			ll a,b;
			cin >> a >> b;
			d[a]++;
			d[b]++;
		}
		if(d[x]<=1 || n%2==0){
			cout << "Ayush\n";
		}else{
			cout << "Ashish\n";
		}
	}
	//cout<<double(clock()-T)/CLOCKS_PER_SEC<<'\n';
	return 0;
 
}
