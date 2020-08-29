#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << "\n";
#define debv(v) for (auto usb: v) cout << usb << " "; cout << "\n";

// n == (1 \/ 0) ????, memory?

void solve(){

	string s;
	int x;
	cin >> s >> x;
	vector<char> w(sz(s), '1');
	
	for (int i = 0; i < sz(s); i++)
	{
		if(s[i] == '0'){
			if(i - x >= 0) w[i - x] = '0';
			if(i + x < sz(s)) w[i + x] = '0';
		}
	}
	
	bool valid = true;
	
	for (int i = 0; i < sz(s); i++)
	{
		bool a = (i - x >= 0) && w[i - x] == '1';
		bool b = (i + x < sz(s)) && w[i + x] == '1';
		if(s[i] == '1' && !(a || b)) valid = false;
	}
	
	if(valid){
		for(char c: w) cout << c;
		cout << "\n";
	}
	else cout << "-1\n";
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
