#include <bits/stdc++.h>
 
using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	s += "##";
	int ans = 0, start = 0, end = n - 1, help = 0;
		
	while(start <= end){
		while(start < n && s[start] == '@') start++;
		int next = start + 1;
		while(next < n && s[next] == '@') next++;
		if(start > end) break;
		
		if(s[start] == s[next]){
			int i = start;
			while(s[start] == s[i] || s[start] == '@') start++;
		} else {
			help = max(start+1, help);
			while(help <= end && !(s[help]!='@' && s[help] == s[help+1] && s[help+1] == s[help+2])) help++;

			if(help >= end + 1){
				s[end] = '@';
				while(end >= 0 && s[end] == '@') end--;
			} else {
				s[help] = '@';
			}
		
			start++;
			while(s[start] == '@') start++;
		}
		ans++;
	}

	cout << ans << "\n";
	return;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	int tt = 1;
	cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}
