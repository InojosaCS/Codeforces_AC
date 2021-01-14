#include <bits/stdc++.h> 

using namespace std; 

void solve(int test){
    int n, k;
    cin >> n >> k;
    
    int a[k+1];
    
    for (int i = 1; i <= k; i++)
    {
	a[i] = -i;
    }
    
    sort(a + k - (n-k), a + k + 1);
    
    for (int i = 0; i < k; i++)
    {
	cout << -a[i+1] << " \n"[i==k-1];
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int32_t testCases = 1;
    cin >> testCases;
    
    while(testCases-->0) solve(testCases + 2);
    
    return 0;
}	
