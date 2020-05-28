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
#define deb(i) cout << "Aqui " << (ll) i << "\n";
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		priority_queue <tuple<ll,ll,ll>> q;
		vll ans(n+2);
		q.push({-n, -1, -n});

		for (int i = 1; i <= n; i++)
		{
			ll val,l,r;
			tie(val,l,r) = q.top();
			q.pop();
			l = -l; r = -r;
			//cout << i << " " << -val << " " << l << " " << r << "\n";

			if((r-l)%2){
				ans[(l+r)/2] = i;
				if((l+r)/2 - 1 - l >= 0)
				{	
					//cout << ((l+r)/2 - 1 - l) << " " << l << " " << ((l+r)/2 - 1) << " added\n";
					q.push({((l+r)/2 - 1 - l), -l, -((l+r)/2 - 1)});
				}
				if((r - (l+r)/2 + 1) >= 0)
				{
					//cout << (r - ((l+r)/2 + 1)) << " " << ((l+r)/2 + 1) << " " << -r << " added\n";
					q.push({(r - ((l+r)/2 + 1)), -((l+r)/2 + 1), -r});
				}
				
			}else{
				ans[(l+r+1)/2] = i;
				if((l+r+1)/2 - 1 - l >= 0)
				{
					//cout << -((l+r+1)/2 - 1 - l) << " " << -l << " " << -((l+r+1)/2 - 1) << " added\n";
					q.push({((l+r+1)/2 - 1 - l), -l, -((l+r+1)/2 - 1)});
				}
				if((r - (l+r+1)/2 + 1) >= 0)
				{
					//cout << -(r - ((l+r+1)/2 + 1)) << " " << -((l+r+1)/2 + 1) << " " << -r << " added\n";
					q.push({(r - ((l+r+1)/2 + 1)), -((l+r+1)/2 + 1), -r});
				}
			}
		}
		for (int i = 1; i <= n; i++) cout << ans[i] << " ";
		endl
	}
	
	return 0;

}
