#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int what = 0;
	
	for (int i = 0; i+1 < n; i++)
	{
		if(s[i] == s[i+1]) what++;
	}

	cout << what/2 + what%2 << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	int32_t tt = 1;
	cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}
