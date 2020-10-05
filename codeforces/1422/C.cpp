#include <bits/stdc++.h>
 
using namespace std;

vector<int64_t> ppow10(100123, 1LL);
int64_t inv2;
const int64_t M = 1e9 + 7;

void ppow(){
	int64_t e = M - 2;
	int64_t b = 2LL;
	int64_t r = 1LL;
	
	while(e > 1){
		if(e%2) r = r * b % M;
		e /= 2;
		b = b * b % M;
	}

	inv2 = r * b % M;

	for (int i = 0; i < 1e5+7; i++)
		ppow10[i+1] = ppow10[i] * 10LL % M; 
	
	return;
}

void solve(){
	string a;
	cin >> a;

	ppow();
	int64_t cum = 0LL;
	int64_t sum = 0LL;
	int64_t n = a.size();
	reverse(begin(a), end(a));

	for (int64_t i = 0; i < n; i++)
	{
		int64_t curr = (int64_t) (a[i] - '0');
		sum = (sum + curr * cum % M) % M;
		sum = (sum + (curr * ppow10[i] % M) * ((n-i-1) * (n-i) * inv2 % M) % M) % M;
		cum = (cum + (i+1LL) * ppow10[i] % M) % M;
	}

	cout << sum << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	cout.precision(20);
		
	long double tt = 1;
	//cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}
