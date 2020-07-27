#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);

	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		ll x,y;
		x = y = 0;
		for (int i = 0; i < sz(s); i++)
		{
			if(s[i]=='1') ++x;
			else y++;
		}
		if(min(x,y)%2) cout << "DA\n";
		else cout << "NET\n";
	}

	return 0;
}
