#include <bits/stdc++.h> 

using namespace std; 

void solve(int test){
    int n;
    cin >> n;
    
    int cnt = 0;
    
    if(n == 1){
	cout << "9\n";
	return;
    }
    
    cnt += 2;
    
    cout << 98;
    
    for (int i = 9; i < 9 + n-2; i++)
    {
	cout << i % 10;
    }
    
    
    cout << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int32_t testCases = 1;
    cin >> testCases;
    
    while(testCases-->0) solve(testCases);
    
    return 0;
}	
