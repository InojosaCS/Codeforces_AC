#include <bits/stdc++.h>
 
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (long long) x.size()
#define debug(x) cout << (#x) << " is " << x << "\n"


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.precision(20);
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		bool helper = false;
		int a, b;

		for (int i = 2; i*i <= n; ++i)
		{
			if(n%i==0){
				helper = true;
				a = n/i;
				b = n - a;
				break;
			}
		}
		if(helper){
			cout << a << " " << b << "\n";
		}else{
			cout << 1 << " " << n-1 << "\n";
		}
	}

	return 0;
}
