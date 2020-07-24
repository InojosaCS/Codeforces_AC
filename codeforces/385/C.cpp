#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;

const int N = 1e7+7;
vector<int>primes;
vector<bool> isPrime(N, true);

void sieve(){
	for (int i = 4; i < N; i+=2)
		isPrime[i] = false;
		
	for (int i = 3; i < N; i+=2)
		if(isPrime[i])
			for (int j = 2*i; j < N; j += i)
				isPrime[j] = false;
	
	primes.push_back(2);
	
	for (int i = 3; i < N; i+=2)
		if(isPrime[i])
			primes.push_back(i);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);
	
	sieve();
	int n, mx = 1;
	cin >> n;
	vector<int> cnt(N,0), prefix(N,0);
	
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		mx = max(mx, a);
		++cnt[a];
	}
	
	for(int prime: primes){
		if(prime>mx)
			break;
		
		for (int i = prime; i <= mx; i += prime)
			prefix[prime] += cnt[i];	
			
	}
	
	for (int i = 1; i <= mx; i++)
		prefix[i] = prefix[i] + prefix[i-1];
	
	int m;
	cin >> m;
	
	while(m--){
		int l,r;
		cin >> l >> r;
		cout << prefix[min(mx,r)] - prefix[min(l-1,mx)] << "\n";
	}
	
	return 0;
}
