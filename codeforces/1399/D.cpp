#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;
#define debv(v) for (auto x: v) cout << x << " "; cout << "\n";

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);	
	
	int tt;
	cin >> tt;
	while(tt--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		set<ll> zero,one;
		vector<ll> val(n);
		ll cnt = 1ll;
		
		for (int i = 0; i < n; i++)
		{
			if(s[i] == '1'){
				if(zero.size()){
					ll x = *zero.begin();
					val[i] = x;
					zero.erase(x);
					one.insert(x);
				}else{
					val[i] = cnt;
					one.insert(cnt);
					cnt++;
				}
			}
			if(s[i] == '0'){
				if(one.size()){
					ll x = *one.begin();
					val[i] = x;
					one.erase(x);
					zero.insert(x);
				}else{
					val[i] = cnt;
					zero.insert(cnt);
					cnt++;
				}
			}
		}
		
		cout << *max_element(all(val)) << "\n";
		for (int i = 0; i < n; i++)
		{
			cout << val[i] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
