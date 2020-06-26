#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
 
#define solve imAwesome
#define for0(i,n) for(int i=0; i<(int)n; i++)
#define forn(i,n) for(int i=1; i<=(int)n; i++)
#define pb push_back
#define f first
#define s second
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define all(x) x.begin(),x.end()
#define sz(s) (ll) s.size()
#define endl cout << "\n";
#define deb(i) cout << "Aqui " << (ld) i << "\n";
//#define int long long 

int main(){
	
	ll n,reach=0ll,sum=0ll;
	cin  >> n;
	vll a(n), preffix(n),suffix(n);
	
	for(int i=0; i<n;i++)
	{
		cin >> a[i];
		reach += a[i];
	}
	
	if(reach%3==0 && n>2){
		reach /= 3;
		ll r=0ll;
		
		for (int i = 0; i < n; i++)
			preffix[i] = sum += a[i];
		
		sum = 0ll;
		
		for (int i = n-1; i > -1; i--)
		{
			if(sum==reach && i!=n-1){
				r++;
			}
			suffix[i]=r;
			sum+=a[i];
		}
		
		ll ans = 0ll;
		
		for (int i = 0; i < n-2; i++)
		{
			if(preffix[i]==reach){
				ans += suffix[i+1];
			}
		}
		
		cout << ans << "\n";
	}else{
		cout << "0\n";
	}
	return 0;
	
}
