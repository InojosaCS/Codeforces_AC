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
	
	int64_t ans = 0;
	
	for (int i = 0; i < n && n!=1; i++)
	{	
		if(i == 0 && a[i]>a[i+1]) ans += a[i];
		else if(i == n-1 && a[i] > a[i-1]) ans += a[i];
		else if (is(0, i, n-1) && peak(a[i-1], a[i], a[i+1])) ans += a[i];
		else if (is(0, i, n-1) && peak(-a[i-1], -a[i], -a[i+1])) ans -= a[i];
	}
	
	if(n == 1) cout << a[0] << "\n";
	else cout << ans << "\n";
	int l,r;

	
	for (int qq = 0; qq < q; qq++)
	{
		cin >> l >> r;
		--l; --r;
		map<int, bool> vis;
		
		for(int i = l-1; i <= l+1; i++){
			vis[i] = true;
			if(i == 0 && a[i]>a[i+1]) ans -= a[i];
			else if(i == n-1 && a[i] > a[i-1]) ans -= a[i];
			else if (is(0, i, n-1) && peak(a[i-1], a[i], a[i+1])) ans -= a[i];
			else if (is(0, i, n-1) && peak(-a[i-1], -a[i], -a[i+1])) ans += a[i];
		}
		for(int i = r-1; i <= r+1; i++){
			if(vis[i]){
				vis[i] = 0;
				continue;
			}
			if(i == 0 && a[i]>a[i+1]) ans -= a[i];
			else if(i == n-1 && a[i] > a[i-1]) ans -= a[i];
			else if (is(0, i, n-1) && peak(a[i-1], a[i], a[i+1])) ans -= a[i];
			else if (is(0, i, n-1) && peak(-a[i-1], -a[i], -a[i+1])) ans += a[i];
		}
		
		swap(a[l], a[r]);
		
		for(int i = l-1; i <= l+1; i++){
			vis[i] = 1;
			if(i == 0 && a[i]>a[i+1]) ans += a[i];
			else if(i == n-1 && a[i] > a[i-1]) ans += a[i];
			else if (is(0, i, n-1) && peak(a[i-1], a[i], a[i+1])) ans += a[i];
			else if (is(0, i, n-1) && peak(-a[i-1], -a[i], -a[i+1])) ans -= a[i];
		}
		
		for(int i = r-1; i <= r+1; i++){
			if(vis[i]){
				vis[i] = 0;
				continue;
			}
			if(i == 0 && a[i]>a[i+1]) ans += a[i];
			else if(i == n-1 && a[i] > a[i-1]) ans += a[i];
			else if (is(0, i, n-1) && peak(a[i-1], a[i], a[i+1])) ans += a[i];
			else if (is(0, i, n-1) && peak(-a[i-1], -a[i], -a[i+1])) ans -= a[i];
		}
		
		if(n == 1) cout << a[0] << "\n";
		else cout << ans << "\n";
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
		
	int t = 1;
	cin >> t;

	while(t-->0) solve();
	
	return 0;
}
