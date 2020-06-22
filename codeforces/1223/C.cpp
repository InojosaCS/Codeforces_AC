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

 
int main(){
	//auto T=clock();
	
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.precision(20);

	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		vll tickets(n);
		for(int i=0; i<n; i++)
		{
			cin >> tickets[i];
			tickets[i]/=100ll;
		}
			
		sort(all(tickets), greater<ll>());
		vll prefix(n+1,0ll);
		for(int i=1; i<=n; i++)
			prefix[i] += (tickets[i-1]+prefix[i-1]);
			
		ll x,a,y,b,k,mcm,ans=-1;
		cin >> x >> a >> y >> b >> k;
		mcm = (ll) (a*b)/(ll)__gcd(a,b);
		
		if(x<y){
			ll tempa = a, tempb = b, tempx = x, tempy = y;
			a = tempb;
			b = tempa;
			x = tempy;
			y = tempx;
		}
		
		for(ll i=0; i<n; i+=1ll)
		{
			ll imcm = (i+1ll)/mcm;
			ll sum = 0ll,ia = (i+1ll)/a-imcm,ib = (i+1ll)/b-imcm;
			sum += (x+y)*(prefix[imcm]);
			sum += (x*(prefix[ia+imcm]-prefix[imcm]));
			sum += (y*(prefix[ia+ib+imcm]-prefix[ia+imcm]));
			if(sum>=k){
				ans = i+1;
				break;
			}
		}
		
		cout << ans << "\n";
	}
	//cout<<double(clock()-T)/CLOCKS_PER_SEC<<'\n';
	return 0;
 
}
