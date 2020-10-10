#include <bits/stdc++.h>
 
using namespace std;
 
void solve(){
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int64_t x;
		cin >> x;
		if(x >= 15LL &&  x % 14LL > 0LL &&  x % 14LL < 7LL) cout << "YES\n";
		else cout << "NO\n";
	}
	
	
	
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
		
	int t = 1;
	//cin >> t;

	while(t-->0) solve();
	
	return 0;
}
