#include <bits/stdc++.h> 

using namespace std; 

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    
    int index = n+1;
    
    for (int i = 0; i < n; i++)
    {
	cin >> a[i];
	if(a[i] != i+1) index = i+1;
    }
    
    long double neg = 1;
    bool ok = false;
    
    for (int i = 0; i < m; i++)
    {
	int r;
	long double p;
	cin >> r >> p;
	if(r >= index) ok = true, neg *= (1.0 - p);
    }
    
    if(!ok && index == n+1) neg = 0;
    
    cout << 1 - neg << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
    
    int32_t testCases = 1;
    cin >> testCases;

    while(testCases-->0) solve();
    
    return 0;
}	
