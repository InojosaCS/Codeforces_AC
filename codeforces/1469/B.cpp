#include <bits/stdc++.h> 
 
using namespace std; 

void solve(){
    int n, m;
    cin >> n;
    
    vector<int> a(n);
    int mx1 = 0, mx2 = 0, sum = 0;
    
    for (int i = 0; i < n; i++)
    {
	cin >> a[i];
	sum += a[i];
	mx1 = max(mx1, sum);
    }
    
    cin >> m;
    vector<int> b(m);
    sum = 0;
       
    for (int i = 0; i < m; i++)
    {
	cin >> b[i];
	sum += b[i];
	mx2 = max(mx2, sum);
    }
    
    cout << mx1 + mx2 << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int32_t testCase = 1;
    cin >> testCase;

    while(testCase-->0) solve();
    
    return 0;
}	
