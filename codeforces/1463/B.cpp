#include <bits/stdc++.h> 
 
using namespace std; 

void solve(int test){
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
	int x;
	cin >> x;
	int pp = 1;
	while(pp <= x) pp *= 2;
	cout << pp / 2 << " \n"[i==n-1];
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
