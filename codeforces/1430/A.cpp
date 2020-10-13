#include <bits/stdc++.h>
 
using namespace std;

vector<pair<int,int>> a(7000, {-1,-1});

void solve(){
	int n;
	cin >> n;
	
	for (int i = 0; i <= n; i+=7)
	{
		if(a[n-i].first != -1){
			cout << a[n-i].second/3 << " " << a[n-i].first/5 << " " << i/7 << "\n";
			return;
		}
	}
	
	cout << "-1\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	for (int i = 0; i < 1007; i+=5)
	{
		for (int j = 0; j < 1007; j+=3)
		{
			a[i+j] = {i, j};
		}
	}
		
	int tt = 1;
	cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}
