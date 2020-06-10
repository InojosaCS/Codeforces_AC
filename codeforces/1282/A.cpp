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
#define sz(s) (ll) s.size()
#define endl cout << "\n";
#define deb(i) cout << "Aqui " << (ld) i << "\n";
#define pi 3.141592653589793238462643383279502884197169399375105820974944592307816406286L




int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.precision(20);
	
	//auto T=clock();
	
	int t;
	cin >> t;
	while(t--){
		ll a,b,c,r,x,y;
		cin >> a >> b >> c >> r;
		x=min(a,b);
		y=max(a,b); 
	
		if(x<=c && c<=y){
			cout << (y-x)-min((min(r, c-x) + min(r,y-c)), (y-x)) << "\n";
		}else if(c<x){
			cout << (y-x)-min((y-x),(max(c+r-x, 0ll))) << "\n";
		}else{
			cout << (y-x)-min((y-x),(max(y-(c-r),0ll))) << "\n";
		}
	}
	
	//cout<<double(clock()-T)/CLOCKS_PER_SEC<<'\n';
	return 0;
 
}
