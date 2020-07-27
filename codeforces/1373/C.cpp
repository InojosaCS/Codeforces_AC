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
		ll x,y,cnt,sum = sz(s);
		x = y = cnt = 0;
		
		for (int i = 0; i < sz(s); i++)
		{
			if(s[i]=='-') --x;
			else x++;
			if(x + cnt < 0){
				sum += (i+1ll);
				cnt++;
			}
		}
		cout << sum << "\n";
	}

	return 0;
}
