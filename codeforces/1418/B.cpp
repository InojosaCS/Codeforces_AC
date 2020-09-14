#include <bits/stdc++.h>
 
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int64_t> a(n), l(n), helper, pre(n);
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	for (int i = 0; i < n; i++)
	{
		cin >> l[i];
		if(l[i] == 0){
			helper.emplace_back(a[i]);
		} else {
			pre[i] = a[i];
		}
	}
	
	sort(begin(helper), end(helper));
	int index = 0;
	
	for (int i = n -1; i > -1; i--)
	{
		if(l[i] == 0){
			pre[i] = helper[index];
			++index;
		}
	}
	
	for (int i = 0; i < n; i++)
		cout << pre[i] << " ";

	cout << "\n";// << k << "\n";
	
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
