#include <bits/stdc++.h>

using namespace std;

void solve(){
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	
	int64_t p = 1;
	int64_t ans = 0;
	
	for (int i = 0; i < s.size(); i++)
	{
		ans = (ans + (s[i] - '0') * p) % 4;
		p = (p * 10) % 4;
	}
	
	if(ans == 0) cout << "4\n";
	else cout << "0\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int32_t tt = 1;
	//cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}	
