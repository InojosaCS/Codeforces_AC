#include <bits/stdc++.h> 

using namespace std; 

void solve(int test){
    int64_t n, x;
    cin >> n >> x;
    
    vector<pair<int64_t, int64_t>> a(n,{0,1});
    
    for (int i = 0; i < n; i++)
    {
	cin >> a[i].first;
    }
    
    int64_t sum = 0;
    
    for (int i = 0; i < (int) a.size(); i++)
    {
	if(a[i].first % x) break;
	a.push_back({a[i].first / x, a[i].second * x});
    }
    
    for (int i = 0; i < (int) a.size(); i++)
    {
	sum += a[i].first * a[i].second;
    }
    
    cout << sum << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int32_t testCases = 1;
    cin >> testCases;
    
    while(testCases-->0) solve(testCases);
    
    return 0;
}	
