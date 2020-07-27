#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);

	int tt;
	cin >> tt;
	while(tt--){
		ll a,b;
		cin >> a >> b;
		ll cum = 0ll, cnt = 0ll;
		while(cum<=b){
			cum = cum * 10ll + 9ll;
			cnt++;
		}
		cnt--;
		cout << a*cnt << "\n";
	}

	return 0;
}
