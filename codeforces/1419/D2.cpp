#include <bits/stdc++.h>
 
using namespace std;
 
void solve(){
	int n;
	cin >> n;
	vector<int64_t> a(n);
	vector<int64_t> ans(n);
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	sort(a.begin(), a.end());
	int index = 0;
	
	for (int i = 1; i < n; i+=2)
		ans[i] = a[index++];
	
	for (int i = 0; i < n; i+=2)
		ans[i] = a[index++];

	index = 0;
	
	for (int i = 1; i + 1 < n; i++)
		if(ans[i-1] > ans[i] && ans[i] < ans[i+1])
			index++;
		
	cout << index << "\n";
	
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";	
	
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	int t = 1;
	//cin >> t;

	while(t--)
		solve();
	
	return 0;
}
