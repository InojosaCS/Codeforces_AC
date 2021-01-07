#include <bits/stdc++.h> 

using namespace std; 

const int N = 1e5+7;
vector<bool> p(N, 1);
//vector<int> cnt(1e6+7, 0);
vector<int> primes;

void sieve(){
    
    for (int i = 2; i < N; i++)
    {
	if(!p[i]) continue;
	for (int j = 2*i; j < N; j+=i)
	{
	    p[j] = 0;
	}
    }
    
    for (int i = 2; i < N; i++)
	if(p[i]) primes.push_back(i);
    
    return;
}

void solve(int test){
    int n;
    cin >> n;
    
    vector<int> a(n, 1);
    map<int,int> cnt;
    
    for (int i = 0; i < n; i++)
    {
	int x;
	cin >> x;

	for (int j: primes)
	{
	    if(j * j > x) break;
	    int e = 0;
	    while(x % j == 0){
		e++;
		x /= j;
	    }
	    if(e & 1) a[i] *= j; 
	}
	
	if(x > 1) a[i] *= x;
	cnt[a[i]]++;
    }
   
    int ans0 = 1;
    int ans1 = 0;

    for(auto [x, c]: cnt){
	if(x == 1 || ((c & 1) == 0)) ans1 += c;
	ans0 = max(ans0, c);
    }
        
    ans1 =  max(ans1, ans0);
    
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++)
    {
	int64_t w;
	cin >> w;
	cout << ((w == 0) ? ans0 : ans1) << "\n";
    }

    return;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    sieve();
  
    int32_t testCases = 1;
    cin >> testCases;
    
    while(testCases-->0) solve(testCases);
    
    return 0;
}	
