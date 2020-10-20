#include <bits/stdc++.h>

using namespace std;

void solve(){
    int64_t n;
    cin >> n;
    int64_t a = 1, b = 1;
    
    for (int64_t i = n; i > n/2; i--)
        a *= i;

    for (int64_t i = 1; i <= n/2; i++)
        b *= i;

    cout << (a/b/2)*(b/(n/2))*(b/(n/2)) << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    
	int tt = 1;
	//cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}
