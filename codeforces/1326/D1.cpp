#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;
#define debv(v) for (auto x: v) cout << x << " "; cout << "\n";

const ll P = 31ll, M = 1000000009ll;
vector<ll> l(1e6+7,0ll), r(1e6+7,0ll);

ll expo(ll a, ll b){
	if(b == 0) return 1ll;
	if(b == 1) return a%M;
	else return expo(a*a%M, b/2ll) * ((b%2ll) ? a : 1ll) % M;
}

ll inverse(ll k){
	return expo(k, M-2ll);
}

void hashing(string s){
	ll p = 1ll;
	for (int i = 0; i < sz(s); i++)
	{
		l[i+1] = (l[i] + ((ll)(s[i] - 'a' + 1ll))*p%M)%M;
		p = (p*P)%M;
		
	}
	reverse(all(s));
	p = 1ll;
	
	for (int i = 0; i < sz(s); i++)
	{
		r[i+1] = (r[i] + ((ll)(s[i] - 'a' + 1ll))*p%M)%M;
		p = (p*P)%M;
	}
}

void solve(){
	string s;
	cin >> s;
	hashing(s);
	ll n = sz(s);
	priority_queue<tuple<ll,ll,ll>> q;
	vector<ll> mx(n+1,0ll);
	//for (int i = 0; i < n; i++)
	//{
		//cout << l[i+1] << " ";
	//}
	//cout <<"\n";
	//for (int i = 0; i < n; i++)
	//{
		//cout << r[i+1] << " ";
	//}
	//cout <<"\n";
	for (int i = 1; i <= sz(s); i++)
	{
		if(l[i] == r[i] && i<=n/2){
			mx[i] = i;
			q.push({i+i,i,i});
			//cout << i << "\n";
		}else{
			mx[i] = mx[i-1];
			if(i >= n - mx[i] + 1ll) 
				break;
			//cout << i << " " << mx[i] << "\n";
			//deb(n-mx[i]);deb(n-i);
			//cout << "l: " << ((l[i] - l[mx[i]] + M)%M) << " r: " <<
				//((r[n-mx[i]] - r[n-i] + M)%M)<< "\n";
				
			//cout << "r2: " << ((r[i] - r[mx[i]] + M)%M) << " l2: " <<
				//((l[n-mx[i]] - l[n-i] + M)%M) << "\n";
				
			//deb(inverse(expo(P,mx[i]))); deb(inverse(expo(P,n-i)));
			if(((l[i] - l[mx[i]] + M)%M)*inverse(expo(P,mx[i]))%M 
				== ((r[n-mx[i]] - r[n-i] + M)%M)*inverse(expo(P,n-i))%M){
				//cout << "A " << i << " " << mx[i] << "\n";
				q.push({i+mx[i], i, mx[i]});
			}
			if(((r[i] - r[mx[i]] + M)%M)*inverse(expo(P,mx[i]))%M 
				== ((l[n-mx[i]] - l[n-i] + M)%M)*inverse(expo(P,n-i))%M){
				//cout << "B " << mx[i] << " " << i << "\n";
				q.push({i+mx[i], mx[i], i});
			}
		}
	}

	ll a,b,c;
	tie(a,b,c) = q.top();
	for (int i = 1; i <= b; i++) cout << s[i-1];
	for (int i = n-c+1; i <= sz(s); i++) cout << s[i-1];
	for (int i = 0; i < n+3; i++) l[i] = r[i] = 0ll;
	cout << "\n";
}

int main(){
	
	int tt;
	cin >> tt;
	while(tt--){
		//cout << "CASE : " << tt+1 << "\n"; 
		solve();
	}
	return 0;
}
