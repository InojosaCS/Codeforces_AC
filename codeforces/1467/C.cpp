#include <bits/stdc++.h> 

using namespace std; 

bool peak(int i, int j, int k){
    return (j < i && j < k) || (j > i && j > k);
}

void solve(int test){
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    
    vector<int64_t> a(n1);
    vector<int64_t> b(n2);
    vector<int64_t> c(n3);
    
    int64_t sum1 = 0;
    int64_t sum2 = 0;
    int64_t sum3 = 0;
    
    for (int i = 0; i < n1; i++)
    {
	cin >> a[i];
	sum1 += a[i];
    }
    for (int i = 0; i < n2; i++)
    {
	cin >> b[i];
	sum2 += b[i];
    }
    for (int i = 0; i < n3; i++)
    {
	cin >> c[i];
	sum3 += c[i];
    }
    
    int64_t x = *min_element(a.begin(), a.end());
    int64_t y = *min_element(b.begin(), b.end());
    int64_t z = *min_element(c.begin(), c.end());
    
    int64_t tax = min({x+y, y+z, x+z, sum1, sum2, sum3});
    int64_t all = sum1 + sum2 + sum3;
    cout << all - 2LL * tax << "\n"; 
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int32_t testCases = 1;
    //cin >> testCases;
    
    while(testCases-->0) solve(testCases);
    
    return 0;
}	
