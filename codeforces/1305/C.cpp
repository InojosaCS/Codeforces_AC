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

ll n,m;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	//auto T=clock();

	cin >> n >> m;
	vll a(n);
	ll ans=1ll;
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	if(n<=m){
		for (int i = 0; i < n; i++)
			for(int j=i+1; j<n; j++)
				ans = (ans*abs(a[i]-a[j]))%m;
		cout << ans << '\n';
		
	}else{
		cout << "0\n";
	}
	
	//cout<<double(clock()-T)/CLOCKS_PER_SEC<<'\n';
	return 0;
 
}
