#include <bits/stdc++.h> 
 
using namespace std; 

#define int int64_t

const int MOD = 1e9 + 7;
const int P = 60;

void solve(int test){
    int n;
    cin >> n;
    
    vector<int64_t> a(n);
	
    for (int i = 0; i < n; i++)
	cin >> a[i];
	
    vector<int> f(P, 0);
    
    for (int i = 0; i < P; i++)
    {
	for (int j = 0; j < n; j++)
	{
	    f[i] += ((1LL << i) & a[j]) > 0;
	}
	//cout << "f[" << i << "]: " << f[i] << "\n";
    }
    
    int64_t ans = 0;
    
    for (int j = 0; j < n; j++)
    {
	int64_t lhs = 0; 
	int64_t rhs = 0;

	for (int c = 0; c < P; c++)
	{
	    int64_t cnt = ((1LL << c) & a[j]) ? n : f[c];
	    lhs = (lhs + ( ((1LL << c) % MOD) * ( ((((1LL << c) & a[j]) > 0) * f[c]) % MOD) % MOD)) % MOD;
	    rhs = (rhs + ( ((1LL << c) % MOD) * cnt % MOD) % MOD) % MOD;
	}
	ans = (ans + lhs * rhs % MOD) % MOD;
	//cout << "TEST: " << a[j]  << "\n" << lhs << "\n" << rhs << "\n";
    }

    
    cout <<  ans  << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int32_t testCase = 1;
    cin >> testCase;

    while(testCase-->0) solve(testCase);
    
    return 0;
}	
