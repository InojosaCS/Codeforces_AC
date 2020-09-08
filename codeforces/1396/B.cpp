#include <bits/stdc++.h>
 
using namespace std;

void solve(){
	int n;
	cin >> n;
	int sum = 0, mx = 0;

	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		sum += x;
		mx = max(mx, x);
	}

	if(mx > sum - mx){
		cout << "T\n";
		return;
	}
	if(sum % 2) cout << "T\n";
	else cout << "HL\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 

	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
