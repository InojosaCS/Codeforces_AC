#include <bits/stdc++.h>
 
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (long long) x.size()
#define debug(x) cout << (#x) << " is " << x << "\n";

long long mod = 1e9+7;

long long expo(long long a, long long b){
	if(b==0) return 1ll;
	if(b==1) return a;
	else return (expo((a*a)%mod, b/2)*(b%2ll ? a : 1ll))%mod;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.precision(20);

	long long x, n;
	cin >> x >> n;
	std::vector<long long> primes;

	for (long long i = 2; i*i <= x; ++i)
	{
		if(x%i==0)
			primes.push_back(i);
		while(x%i==0)
			x/=i;
	}

	if(x>1)
		primes.push_back(x);

	map<long long, long long> cnt;

	for (int i = 0; i < sz(primes); ++i)
	{
		long long current = primes[i];
		while(current <= n){
			cnt[primes[i]] += n/current;
			if(current <= n/primes[i])
				current *= primes[i];
			else
				break;
		}
	}

	long long ans = 1ll;

	for (int i = 0; i < sz(primes); ++i)
		ans = (ans * expo(primes[i], cnt[primes[i]]))%mod;
	

	cout << ans << "\n";

	return 0;
}
