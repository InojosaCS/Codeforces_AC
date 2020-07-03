#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
 
#define for0(i,n) for(int i=0; i<(int)n; i++)
#define forn(i,n) for(int i=1; i<=(int)n; i++)
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define sz(s) (ll) s.size()
#define endl cout << "\n";
#define deb(i) cout << "Aqui " << (ld) i << "\n";
//#define int long long 


int main(){
	//auto T=clock();
	//cout<<double(clock()-T)/CLOCKS_PER_SEC<<'\n';
	
	ll n;
	cin >> n;
	vll a(n+1);
	
	for(int i=1;i<=n;i++)
		cin >> a[i];
	
	vll pre(n+5,0ll);			
	set<ll> s;

	for(int i=1;i<=n;i++)
		pre[i] = a[i]+pre[i-1];

	ll ans = 0ll, last = 1;
	s.insert(0);

	for(int start=0; start<=n; start++){
		while(s.find(pre[last]) == s.end() && last <= n){
			s.insert(pre[last]);
			last++;
		}
		ans += (last-1-start);
		s.erase(pre[start]);
	}

	cout << ans << "\n";
	
	return 0; 
}
