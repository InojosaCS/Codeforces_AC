#include <bits/stdc++.h>
 
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (long long) x.size()
#define debug(x) cout << (#x) << " is " << x << "\n"


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.precision(20);
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n+1,0);
		for (int i = 1; i <= n; ++i)
			cin >> a[i];

		int ans = 0, left = 0, right = 0;

		for (int i = 1; i <= n; ++i)
			if(a[i]!=i)
				ans = 1;

		for (int i = 1; i <= n; ++i){
			if(a[i]!=i){
				left = i;
				break;
			}
		}
		for (int i = n; i > 0; --i){
			if(a[i]!=i){
				right = i;
				break;
			}
		}	
		for (int i = left + 1; i < right; ++i)
		{
			if(a[i]==i){
				ans = 2;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}
