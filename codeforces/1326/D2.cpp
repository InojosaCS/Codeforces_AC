#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;
#define debv(v) for (auto x: v) cout << x << " "; cout << "\n";

const ll P = 31ll, M = 330640561ll, P2 = 29ll, M2 = 750034837ll;
vector<ll> l(1e6+7,0ll), r(1e6+7,0ll), invP(1e6+7,1ll);
vector<ll> l2(1e6+7,0ll), r2(1e6+7,0ll), invP2(1e6+7,1ll);

ll expo(ll a, ll b, ll MOD){
	if(b == 0) return 1ll;
	if(b == 1) return a%MOD;
	else return expo(a*a%MOD, b/2ll, MOD) * ((b%2ll) ? a : 1ll) % MOD;
}

void inverse(){
	ll d = expo(P, M-2ll, M);
	ll d2 = expo(P2, M2-2ll, M2);
	
	for (int i = 1; i < 1e6+7; i++)
	{
		invP[i] = invP[i-1]*d%M;
		invP2[i] = invP2[i-1]*d2%M2;
	}
}

void hashing(string s){
	ll p = 1ll, p2 = 1ll;
	for (int i = 0; i < sz(s); i++)
	{
		l[i+1] = (l[i] + ((ll)(s[i] - 'a' + 1ll))*p%M)%M;
		p = (p*P)%M;
		l2[i+1] = (l2[i] + ((ll)(s[i] - 'a' + 1ll))*p2%M2)%M2;
		p2 = (p2*P2)%M2;
		
	}
	reverse(all(s));
	p2 = p = 1ll;
	
	for (int i = 0; i < sz(s); i++)
	{
		r[i+1] = (r[i] + ((ll)(s[i] - 'a' + 1ll))*p%M)%M;
		p = (p*P)%M;
		r2[i+1] = (r2[i] + ((ll)(s[i] - 'a' + 1ll))*p2%M2)%M2;
		p2 = (p2*P2)%M2;
	}
}

void solve(){
	string s;
	cin >> s;
	hashing(s);
	ll n = sz(s);
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
	ll b = 1ll, c = 0ll, a = 1ll;
	
	for (int i = 1; i <= sz(s); i++)
	{
		if(l[i] == r[i] && l2[i] == r2[i] && i<=n/2){
			mx[i] = i;
			if(i + i > a){
				a = i + i;
				b = c = i;
			}
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
			if(	(((l[i] - l[mx[i]] + M)%M)*invP[mx[i]]%M == ((r[n-mx[i]] - r[n-i] + M)%M)*invP[n-i]%M)
				&& 
				(((l2[i] - l2[mx[i]] + M2)%M2)*invP2[mx[i]]%M2 == ((r2[n-mx[i]] - r2[n-i] + M2)%M2)*invP2[n-i]%M2)){
				//cout << "A " << i << " " << mx[i] << "\n";
				if(i + mx[i] > a){
					a = i + mx[i];
					b = i;
					c = mx[i];
				}
			}
			if( (((r[i] - r[mx[i]] + M)%M)*invP[mx[i]]%M == ((l[n-mx[i]] - l[n-i] + M)%M)*invP[n-i]%M)
				 &&
				(((r2[i] - r2[mx[i]] + M2)%M2)*invP2[mx[i]]%M2 == ((l2[n-mx[i]] - l2[n-i] + M2)%M2)*invP2[n-i]%M2)){
				//cout << "B " << mx[i] << " " << i << "\n";
				if(i + mx[i] > a){
					a = i + mx[i];
					b = mx[i];
					c = i;
				}
			}
		}
	}


	for (int i = 1; i <= b; i++) cout << s[i-1];
	for (int i = n-c+1; i <= sz(s); i++) cout << s[i-1];
	for (int i = 0; i < n+3; i++) l2[i] = r2[i] = l[i] = r[i] = 0ll;
	cout << "\n";
}

int main(){
	
	int tt;
	cin >> tt;
	inverse();
	while(tt--){
		//cout << "CASE : " << tt+1 << "\n"; 
		solve();
	}
	return 0;
}
