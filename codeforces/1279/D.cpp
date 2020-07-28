#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl
//#define int long long

const ll M = 998244353ll;

ll expo(ll a, ll b){
	if(b==0) return 1ll;
	if(b==1) return a%M;
	return expo(a*a%M, b/2ll)*(b%2 ? a : 1ll)%M;
}

ll inverse(ll k){
	return expo(k, M-2);
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);

	ll n, sum = 0ll;
	cin >> n;
	vector<vector<ll>> g(1e6+7);
	map<pair<ll,ll>, bool> visited;
	map<ll,ll> freq;
	
	for (int i = 0; i < n; i++)
	{
		ll k;
		cin >> k;
		for(int j = 0; j < k; j++){
			ll a;
			cin >> a;
			g[i].push_back(a);
			if(!visited[{i,a}]){
				visited[{i,a}] = true;
				freq[a]++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for(ll x: g[i]){
			ll current = ((inverse(n)*inverse(sz(g[i]))%M)*freq[x]%M)*inverse(n)%M;
			sum = (sum + current)%M;
		}
	}
	
	cout << sum << "\n";
    return 0;
}
