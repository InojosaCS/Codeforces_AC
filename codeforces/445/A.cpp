#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char x;
			cin >> x;
			if(x == '.' && i&1 && j%2==1) cout << 'W';
			else if(x == '.' && i&1 && j%2==0) cout << 'B';
			else if(x == '.' && i%2==0 && j%2==1) cout << 'B';
			else if(x == '.' && i%2==0 && j%2==0) cout << 'W';
			else cout << '-';
		}
		cout << "\n";
	}
	
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int32_t tt = 1;
	//cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}	
