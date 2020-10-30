#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	string str;
	cin >> n >> str;
	
	int sum = 0, start = 0;
	vector<pair<int,int>> mustCheck;
	
	for (int i = 0; i < n; i++)
	{
		if(str[i] == '(') sum++;
		else sum--;
		if(sum == 0){
			mustCheck.push_back({start, i});
			start = i+1;
		}
	}
	
	if(sum != 0){
		cout << "-1\n";
		return;
	}
	
	int ans = 0;
	
	for(auto current: mustCheck){
		int cum = 0;
		bool bad = false;
		for (int i = current.first; i <= current.second; i++)
		{
			if(str[i] == '(') cum++;
			else cum--;
			if(cum < 0){
				bad = true;
				break;
			}
		}
		if(bad) ans += current.second - current.first + 1;
	}
	
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	int32_t tt = 1;
	//cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}
