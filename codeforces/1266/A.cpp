#include <bits/stdc++.h>
 
using namespace std;
 
void solve(){
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		
		if(s=="0"){
			cout << "red\n"; 
			continue;
		}
		
		int current = 0;
		sort(s.begin(), s.end());
		bool ten = s[0] == '0';
		bool par = false;
		
		for (int j = 1; j < (int) s.size(); j++)
		{
			int now = s[j] - '0';
			if(now % 2 == 0) par = true;
			current += now;
		}
		
		if(ten && par && current % 3 == 0) cout << "red\n";
		else cout << "cyan\n";
	}
	
	
	
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
		
	int t = 1;
	//cin >> t;

	while(t-->0) solve();
	
	return 0;
}
