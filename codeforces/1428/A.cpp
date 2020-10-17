#include <bits/stdc++.h>

using namespace std;

void solve(){
    int x,y, x2,y2;
    cin >> x >> y >> x2 >> y2;
    int ans = abs(x-x2)+abs(y-y2);
    if(x == x2 || y == y2) cout << ans << "\n";
    else cout << ans + 2 << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	int tt = 1;
	cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}
