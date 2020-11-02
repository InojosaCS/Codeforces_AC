#include <bits/stdc++.h>

using namespace std;

void solve(){
	int a, b;
	cin >> a >> b;
	string s;
	cin >> s;
	int n = s.size();
	
	if(n == 1){
		if(s[0] == '0'){
			cout << 0 << "\n";
		} else {
			cout << a << "\n";
		}
		return;
	}
	
	if(n == 2){
		if(s[0] == '1' || s[1] == '1'){
			cout << a << "\n";
		} else {
			cout << 0 << "\n";
		}
		return;
	}
	
	int ans = 0;
	int l = n;
	int curr = 0;
	
	for (int i = 0; i < n; i++)
	{
		if(s[i] == '1'){
			l = i;
			ans = a;
			break;
		}
	}
	
	for (int i = l; i < n; i++)
	{
		if(s[i] == '0') curr++;
		else {
			ans += min(curr*b, a);
			curr = 0;
		}
	}
	
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int32_t tt = 1;
	cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}	
