#include <bits/stdc++.h> 
 
using namespace std; 

void solve(int test){
    int n;
    cin >> n;
    
    cout << n-1 << "\n";
    
    for (int i = 2; i <= n; i++)
    {
	cout << i << " \n"[i==n];
    }
    
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int32_t testCase = 1;
    cin >> testCase;

    while(testCase-->0) solve(testCase);
    
    return 0;
}	
