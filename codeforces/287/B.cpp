#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define debug(x) cout << (#x) << " is " << (x) << endl;
#define ll long long
 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);
 
	long long n,k;
	cin >> n >> k;
	ll l = 0, r = k;

	if(k*(k+1ll)/2ll - (k-1) < n){
		cout << "-1\n";
		return 0;
	}

	ll ans = 1;

	while(l<=r){
		long long mid = (l+r)/2ll;
		long long current = k*(k+1ll)/2ll - (k-mid)*(k-mid+1ll)/2ll - (mid-1ll);
		if(current>=n){
			r = mid - 1ll;
			ans = mid;
		}else{
			l = mid + 1ll;
		}
	}
	cout << ans << "\n";
	return 0;
}