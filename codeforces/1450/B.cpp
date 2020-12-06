#include <bits/stdc++.h> 
 
using namespace std; 

void solve(){
    int n, k;
    cin >> n >> k;
    
    vector<pair<int, int>> p(n);
    
    for (int i = 0; i < n; i++)
    {
	cin >> p[i].first >> p[i].second;
    }
    
    for (int i = 0; i < n; i++)
    {
	int cnt = 0;
	for (int j = 0; j < n; j++)
	{
	    if(abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second) <= k){
		cnt++;
	    }
	}
	if(cnt == n){
	    cout << "1\n";
	    return;
	}
    }
    
    cout << "-1\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int32_t testCase = 1;
    cin >> testCase;

    while(testCase-->0) solve();
    
    return 0;
}	
