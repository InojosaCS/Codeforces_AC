#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << "\n";
#define debv(v) for (auto usb: v) cout << usb << " "; cout << "\n";

// n == (1 \/ 0) ????, memory?

void solve(){
	ll n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	
	for (int i = 0; i + k < n; i++)
	{
		if(s[i] == '1' && s[i+k] == '?') s[i+k] = '1';
		else if(s[i] == '0' && s[i+k] == '?') s[i+k] = '0';
		else if(s[i] == '?' && s[i+k] == '1') s[i] = '1';
		else if(s[i] == '?' && s[i+k] == '0') s[i] = '0';
	}
	
	for (int i = n-1; i - k > -1; i--)
	{
		if(s[i] == '1' && s[i-k] == '?') s[i-k] = '1';
		else if(s[i] == '0' && s[i-k] == '?') s[i-k] = '0';
		else if(s[i] == '?' && s[i-k] == '1') s[i] = '1';
		else if(s[i] == '?' && s[i-k] == '0') s[i] = '0';
	}
	
	int res = 0, res2 = 0;
	
	for (int i = 0; i < k; i++){
		if(s[i] == '1')
			res++;
		if(s[i] == '0')
			res2++;
	}
	
	//cout << res << " " << res2 << "\n";
	
	if(res > k / 2 || res2 > k / 2){
			cout << "NO\n";
			return;
	}
	
	for (int i = 0; i + k < n; i++)
	{
		if(s[i] != s[i+k]){
			cout << "NO\n";
			return;
		}
	}
	
	cout << "YES\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(20);	
		
	int t = 1;
	cin >> t;

	while(t--) solve();
	//cout << "OK\n";
	
	return 0;
}
