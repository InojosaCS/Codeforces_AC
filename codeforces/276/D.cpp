#include <bits/stdc++.h>
 
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define debug(x) cout << (#x) << " is " << x << "\n"

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	long long a,b,l,r;
	cin >> a >> b;
	l = a;
	r = b;
	const int N = 63;
	bitset<N> y(a), x(b);
	
	for (int i = N-1; i >= 0; --i)
	{
		
		if(x[i]==0 && y[i]==0 && a+(1ll << i)<=r){
			y[i]=1;
			a+=(1ll<<i);
		}else if(x[i]==1 && y[i]==1 && b-(1ll << i)>=l){
			x[i]=0;
			b-=(1ll<<i);
		}
		// cout << a << " " << b << "\n";
		// cout << x << "\n" << y << "\n\\\\\\\\\\\\\n";
	}
	cout << (a^b) << "\n";
	return 0;
}
