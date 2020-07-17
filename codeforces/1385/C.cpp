#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define debug(x) cout << (#x) << " is " << (x) << endl

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);
	
	int t;
	cin >> t;
	while(t--){
		int n, mx = 0;
		cin >> n;
		vector<int> a(n);
		std::vector<bool> visited(100, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
			if(i>=n-2){
				mx = max(mx, a[i]);
			}
		}
		if(n<=2){
			cout << "0\n";
			continue;
		}
		int ans = 0;
		
		for (int i = n-2; i >-1 ; --i)
		{
			if(a[i]<a[i+1]){
				int j = i;
				while(j && a[j]>=a[j-1]){
					j--;
				}
				ans = j;
				break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}