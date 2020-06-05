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
		ll n;
		cin >> n;
		vll d(n,0ll);
		for0(i,n) cin >> d[i];
		set <ll> m;
		string ans="YES\n";
		for (ll i = 0; i < n; i++)
		{
			ll mod=((i%n)+n)%n;
			ll nxt = (((i+d[mod])%n)+n)%n;
			if(m.find(nxt)!=m.end()){
				ans = "NO\n";
				break;
			}
			m.insert(nxt);
		}
		cout << ans;
	}
	//cout<<double(clock()-T)/CLOCKS_PER_SEC<<'\n';
	return 0;
 
}
