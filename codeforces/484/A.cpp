#include <bits/stdc++.h>
 
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (long long) x.size()
#define debug(x) cout << (#x) << " is " << x << "\n"

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int t;
	cin >> t;

	while(t--){	
		long long l,r,ans=0ll;
		cin >> l >> r;
		const int N = 63;
		bitset<N> left(l), right(r);
		bool diff = false;

		for (long long i = N-1; i >= 0; --i)
		{
			if(diff)
				left[i] = 1;
			else if(i && left[i]!=right[i])
				diff = true;
			ans += (((long long)left[i]) << i);
		}
		ans = right.count() > left.count() ? r : ans;
		cout << ans << "\n";
	}
	return 0;
}
