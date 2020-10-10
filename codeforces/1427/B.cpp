#include <bits/stdc++.h>
 
using namespace std;

void solve(){
	int n, k, cheat = 0;
	cin >> n >> k;
	string s;
	cin >> s;
	set<tuple<int,int,int>> ord;
	set<tuple<int,int,int>> bck;
	
	int start = 0, end = 0;
	
	for (int i = 0; i < n; i++)
	{
		if(s[i] == 'L'){
			end++;
		} else {
			if(start == 0) bck.insert({end-start, -start, end});
			if(start && end) ord.insert({end-start, -start, end});
			end = start = i+1;
		}
	}
	
	for(auto x: ord){
		if(cheat >= k) break;
		int a,b,c;
		tie(a,b,c) = x;
		for (int i = -b; i < c; i++)
		{
			if(cheat >= k) break;
			s[i] = 'W';
			cheat++;
		}
		
	}
	
	for (int i = start; i < end; i++)
	{
		if(cheat >= k) break;
		s[i] = 'W';
		cheat++;
	}
	
	for(auto x: bck){
		if(cheat >= k) break;
		int a,b,c;
		tie(a,b,c) = x;
		for (int i = c-1; i >= -b; i--)
		{
			if(cheat >= k) break;
			s[i] = 'W';
			cheat++;
		}
		
	}
	
	int64_t sum = s[0] == 'W';
	
	for (int i = 1; i < n; i++)
	{
		if(s[i] == 'W' && s[i-1] == 'W'){
			sum += 2;
		} else if(s[i] == 'W') {
			sum++;
		}
	}
	
	cout << sum << "\n";
	
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
