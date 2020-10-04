#include <bits/stdc++.h>
 
using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	int64_t a[n][m];
	int64_t diff[n][m];
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> a[i][j];
			diff[i][j] = a[i][j];
		}
	}
	
	int64_t sum = 0LL;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			vector<int64_t> f;
			f.emplace_back(a[i][j]);
			f.emplace_back(a[i][m-1-j]);
			f.emplace_back(a[n-1-i][j]);
			f.emplace_back(a[n-1-i][m-1-j]);
			sort(begin(f), end(f));
			int64_t median = (f[1] + f[2]) / 2;
			a[i][j] = a[i][m-1-j] = a[n-1-i][j] = a[n-1-i][m-1-j] = median;
		}
	}
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			sum += abs(diff[i][j] - a[i][j]);
			
	cout << sum << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	cout.precision(20);
		
	long double tt = 1;
	cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}
