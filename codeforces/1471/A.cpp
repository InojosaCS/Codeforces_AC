#include <bits/stdc++.h> 

using namespace std; 

void solve(int test){
    int64_t n, x;
    cin >> n >> x;
    
    int64_t a = 0, b = 0;
    
    for (int i = 0; i < n; i++)
    {
	int y;
	cin >> y;
	a += (y + x - 1) / x;
	b += y;
    }
    
    b = (b + x - 1) / x;
    
    cout << min(a, b) << " " << max(a, b) << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int32_t testCases = 1;
    cin >> testCases;
    
    while(testCases-->0) solve(testCases);
    
    return 0;
}	
