#include <bits/stdc++.h> 

using namespace std; 

void solve(){
    int n, k;
    cin >> n >> k;
    char a[] = {'a', 'b', 'c'};
    
    for (int i = 0; i < n; i++)
    {
	cout << a[i%3];
    }
    
    cout << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int32_t testCase = 1;
    cin >> testCase;

    while(testCase-->0) solve();
    
    return 0;
}	
