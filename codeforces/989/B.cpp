#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define debug(x) cout << (#x) << " is " << (x) << endl
#define ll long long
 
 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);
 
	int n,p;
	cin >> n >> p;
	string s;
	cin >> s;
	bool ans = false;

	for (int i = 0; i+p < n; ++i)
	{
		if(s[i]==s[i+p] && s[i]!='.'){
			continue;
		}
		if((s[i]=='1' && s[i+p]=='0') || (s[i]=='0' && s[i+p]=='1')){
			ans = true;
			break;
		}
		if(s[i]=='.' && s[i+p]=='.'){
			s[i]='0';
			s[i+p]='1';
			ans = true;
			break;
		}if(s[i]=='1' && s[i+p]=='.'){
			s[i+p]='0';
			ans = true;
			break;
		}if(s[i]=='.' && s[i+p]=='0'){
			s[i]='1';
			ans = true;
			break;
		}if(s[i]=='.' && s[i+p]=='1'){
			s[i]='0';
			ans = true;
			break;
		}if(s[i]=='0' && s[i+p]=='.'){
			s[i+p]='1';
			ans = true;
			break;
		}
	}
	if(ans){
		for (int i = 0; i < n; ++i)
		{
			if(s[i]=='.')
				cout << '0';
			else
				cout << s[i];
		}
		cout << "\n";
	}else{
		cout << "No\n";
	}
	return 0;
}