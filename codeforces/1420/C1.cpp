#include <bits/stdc++.h>
 
using namespace std;

bool is(int a, int b, int c){
	return a < b && b < c;
}

bool peak(int a, int b, int c){
	return a < b && b > c;
}

void solve(){
	int n,q;
	cin >> n >> q;
	vector<int64_t> a(n);
	

	for (int i = 0; i < n; i++)
		cin >> a[i];

	if(n == 1){
		cout << a[0] << "\n";
		return;
	}
	
	int64_t ans = 0;
	
	for (int i = 0; i < n; i++)
	{	
		if(i == 0 && a[i]>a[i+1]){
			ans += a[i];
		} else if(i == n-1 && a[i] > a[i-1]) {
			ans += a[i];
		} else if (is(0, i, n-1) && peak(a[i-1], a[i], a[i+1])){
			ans += a[i];
		} else if (is(0, i, n-1) && peak(-a[i-1], -a[i], -a[i+1])){
			ans -= a[i];
		}
		//cout << ans << "\n";
	}
	cout << ans << "\n";
	
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
		
	int t = 1;
	cin >> t;

	while(t-->0) solve();
	
	return 0;
}
