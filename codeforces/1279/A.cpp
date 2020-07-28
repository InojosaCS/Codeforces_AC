#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl
//#define int long long



int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);

	int tt;
	cin >> tt;
	while(tt--){
		int a[3];
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a+3);
		if(a[2] - 1 > a[1] + a[0]) cout << "NO\n";
		else cout << "YES\n";
	}
    return 0;
}
