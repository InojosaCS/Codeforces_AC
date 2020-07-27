#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);

	int t;
	cin >> t;
	while(t--){
		ll a,b,c;
		cin >> a >> b >> c;
		ll x, y;
		if(a*b <= c) y = -1;
		else y = b;
		if(a<c) x = 1;
		else x = -1;
		cout << x << " " << y << "\n";
	}

	return 0;
}
