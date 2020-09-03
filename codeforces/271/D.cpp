#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << "\n";
#define debv(v) for (auto usb: v) cout << usb << " "; cout << "\n";

// n == (1 \/ 0) ????, memory?

const int N = 1507;
const ll p = 31;
//const ll p2 = 29;
const ll m = 122749283;
const ll m2 = 459059071;

vector<long long> p_pow(N);
vector<long long> inv_pow(N);
vector<long long> h(N + 1, 0LL);
vector<long long> p_pow2(N);
vector<long long> inv_pow2(N);
vector<long long> h2(N + 1, 0LL);

ll ppow(ll a, ll b, ll x){
	if(b == 0) return 1LL;
	if(b == 1) return a;
	return ppow(a*a%x, b/2, x) * (b%2 ? a : 1LL) % x;
}

ll inv(ll var, ll x){
	return ppow(var, x-2, x) % x;
}

void stringHashing(string const& s){
    int n = s.size();

    inv_pow[0] = p_pow[0] = 1LL;
    inv_pow2[0] = p_pow2[0] = 1LL;
	ll pinv = inv(p,m);
	ll pinv2 = inv(p,m2);
	
    for (int i = 1; i < n; i++){
        p_pow[i] = (p_pow[i-1] * p) % m;
        inv_pow[i] = (inv_pow[i-1] * pinv) % m;
	}
	
    for (int i = 0; i < n; i++)
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

    for (int i = 1; i < n; i++){
        p_pow2[i] = (p_pow2[i-1] * p) % m2;
        inv_pow2[i] = (inv_pow2[i-1] * pinv2) % m2;
	}
	
    for (int i = 0; i < n; i++)
        h2[i+1] = (h2[i] + (s[i] - 'a' + 1) * p_pow2[i]) % m2;

}

void solve(){
	string s;
	cin >> s;
	
	stringHashing(s);
	map<int,bool> binary;
	
	for(char foo = 'a', x; foo <= 'z'; ++foo){
		cin >> x;
		binary[foo - 'a'] = x - '0';
	}
	
	
	int n = sz(s), k;
	cin  >> k;
	int ans = 0;
	map<pair<int,int>, bool> visited;
	
	//for (int i = 0; i < n+1; i++)
	//{
		//cout << h[i] << " ";
	//}
	//cout << "\n";
	//for (int i = 0; i < n+1; i++)
	//{
		//cout << p_pow[i] << " ";
	//}
	//cout << "\n";
	
	for (int l = 1; l <= n; l++)
	{
		int current = 0;
		for (int i = 0; i <= n - l; i++)
		{
			long long xp = (h[i + l] + m - h[l - 1]) % m;
            xp = (xp * inv_pow[l - 1]) % m;
            
			long long xp2 = (h2[i + l] + m2 - h2[l - 1]) % m2;
            xp2 = (xp2 * inv_pow2[l - 1]) % m2;
            
			if(!binary[s[l + i - 1] - 'a']){
				current++;
			}
			
			if(current <= k && !visited[{xp, xp2}]){
				ans++;
				visited[{xp, xp2}] = 1;
				//cout << current << " " << l << " " << l+i << " " << xp << "\n";
			}
		}
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(20);	

	int t = 1;
	//cin >> t;

	while(t--) solve();
	//cout << "OK\n";
	
	return 0;
}
