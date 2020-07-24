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
		int n;
		cin >> n;
		vector<string> ans(n+1, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
		
		for (int i = 1; i <= n; i++)
		{
			int k;
			cin >> k;
			ans[i] = ans[i-1];
			ans[i][k] = (ans[i][k] == 'a') ? 'z' : 'a';
		}
		
		for (int i = 0; i < n+1; i++)
			cout << ans[i] << "\n";
		
	}
	return 0;
}
