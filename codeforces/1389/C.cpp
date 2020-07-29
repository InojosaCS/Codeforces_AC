#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl
#define debv(v) for (int i = 0; i < sz(a); i++) cout << v[i] << " "; cout << "\n";

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);
	
	int tt;
	cin >> tt;
	while(tt--){
		string s;
		cin >> s;
		vector<ll> ans;
		for (int i = 0; i < 10; i++)
		{
			int lazy = 0;
			for (int k = 0; k < sz(s); k++)
			{
				if(s[k]-'0' == i) lazy++;
			}
			ans.push_back(sz(s)-lazy);
		}
		
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				int a[] = {i,j}, lazy = 0;
				for (int k = 0; k < sz(s); k++)
				{
					if(s[k]-'0' == a[lazy%2]){
						lazy++;
					}
				}
				ans.push_back(sz(s)-lazy+lazy%2);
			}
		}
		cout << *min_element(all(ans)) << "\n";
	}
	return 0;
}
