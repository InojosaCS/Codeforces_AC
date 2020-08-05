#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;
#define debv(v) for (auto x: v) cout << x << " "; cout << "\n";

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);	
	
	ll t;
	cin >> t;
	while(t--){
		ll n;
		string s;
		cin >> n >> s;
		ll cnt = 0ll, ans = 0ll;
		for(char c: s){
			if(c == ')' && cnt){
				cnt--;
			}else if(c == '('){
				cnt++;
			}else{
				ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
