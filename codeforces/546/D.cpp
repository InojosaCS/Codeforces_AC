#include <bits/stdc++.h>
 
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()

const int mx = 5*(1e6)+7;
vector<bool> isPrime(mx, true);
vector<int> prefix(mx, 0), primes;

void sieve(){
	for (int i = 4; i < mx; i+=2)
		isPrime[i]=false;

	for (int i = 3; i < mx; i+=2)
		if(isPrime[i])
			for (int j = 2*i; j < mx; j+=i)
				isPrime[j]=false;

	primes.push_back(2);
	for (int i = 3; i < mx; i+=2)
		if(isPrime[i])
			primes.push_back(i);
}

void getPrefix(){
	for (int i = 1; i < mx; ++i)
	{
		int sum = 0, current = i;
		for(auto x: primes){
			if(x*x>current)
				break;
			while(current%x==0)
			{	
				sum++;
				current/=x;
			}
		}
		if(current>1)
			sum++;
		prefix[i] = prefix[i-1]+sum;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int tt;
	cin >> tt;
	sieve();
	getPrefix();
	while(tt--){
		int a,b;
		cin >> a >> b;
		cout << prefix[a]-prefix[b] << "\n";
	}
	return 0;
}
