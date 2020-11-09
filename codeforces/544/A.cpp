#include <bits/stdc++.h>

using namespace std;

void solve(){
	int k;
	string str;
	cin >> k >> str;
	
	map<char,bool> v;
	map<char,bool> v2;
	int pos = 0;
	
	for(char c: str){
		if(!v[c]){
			v[c] = 1;
			pos++;
		}
	}
	
	if(pos < k){
		cout << "NO\n";
		return;
	}
	
	cout << "YES\n";
	int n = str.size();
	int curr = 0;
	int i = 0;
	
	while (i < n)
	{
		v2[str[i]] = 1;
		while(i < n && (v2[str[i]] || curr == k-1)){
			cout << str[i];
			i++;
		}
		curr++;
		cout << "\n";
	}
	
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int32_t tt = 1;
	//cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}	
