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
		ll n,p,k;
		cin >> n >> p >> k;
		vll a(n), ans, prefix(n+1,0ll);
		for0(i,n) cin >> a[i];
		sort(all(a));
		
		for (int i = 1; i <= n; i++)
			prefix[i]+=(a[i-1]+prefix[i-1]);
		
		for(ll start=0ll; start<k; start++){
			ll x,sizeX;
			
			if(prefix[start]<=p){
				x=prefix[start],sizeX=start;
			}else{
				break;
			}
			
			for (int i = start+k-1; i < n; i+=k)
			{
				if(x+a[i]<=p){
					x+=a[i];
					sizeX=(i+1);
				}
			}
			ans.pb(sizeX);
		}
		cout << *max_element(all(ans)) << "\n";
	}
	//cout<<double(clock()-T)/CLOCKS_PER_SEC<<'\n';
	return 0;
 
}
