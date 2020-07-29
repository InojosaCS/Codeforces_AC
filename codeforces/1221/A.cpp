#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;
#define debv(v) for (int i = 0; i < sz(a); i++) cout << v[i] << " "; cout << "\n";

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);

	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		map<int,int> cnt;
		for (int i = 0; i < n; i++)
		{
			int k;
			cin >> k;
			cnt[k]++;
		}
		ll p = 1;
		while(p<2048){
			cnt[p*2] = cnt[p*2] + cnt[p]/2;
			p *= 2ll;
		}
		if(cnt[2048]) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
