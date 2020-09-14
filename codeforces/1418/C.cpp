#include <bits/stdc++.h>
 
using namespace std;

void solve(){
	int n;
	cin >> n;
	int sum = 0, x, ans = 0;
	
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		sum += x;
		if(x == 1 && i == 0){
			ans++;
			sum = 0;
		}
		
		if(x == 0){
			sum = 0;
		}else if(sum == 3){
			ans++;
			sum = 0;
		}
	}
	cout << ans << "\n";
	
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(20);	
		
	int t = 1;
	cin >> t;

	while(t--) solve();
	//cout << "OK\n";
	
	return 0;
}
