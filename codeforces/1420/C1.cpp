#include <bits/stdc++.h>
 
using namespace std;

void solve(){
	int n, q;
	cin >> n >> q;
	vector<int64_t> a(n);
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	if(n == 1){
		cout << a[0] << "\n";
		return;
	}
	
	bool up = true;
	vector<int64_t> ans;
	
	if(a[0] > a[1]){
		ans.emplace_back(a[0]);
		up = false;
	}
	
	for (int i = 1; i + 1 < n; i++)
	{
		if(up && a[i-1] < a[i] && a[i] > a[i+1]){
			ans.emplace_back(a[i]);
			up = false;
		}
		else if(!up && a[i-1] > a[i] && a[i] < a[i+1]){
			ans.emplace_back(-a[i]);
			up = true;
		}
	}
	
	if(up && a[n-1] > a[n-2]){
		ans.emplace_back(a[n-1]);
	}
	
	int64_t res = -1, sum = 0;
	
	for (int i = 0; i < (int) ans.size(); i++){
		sum += ans[i];
		res = max(sum, res);
	}
	
	cout << res << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
		
	int t = 1;
	cin >> t;

	while(t--) solve();
	
	return 0;
}
