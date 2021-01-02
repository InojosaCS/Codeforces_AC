#include <bits/stdc++.h> 
 
using namespace std; 

void solve(int test){
    int64_t n, w;
    cin >> n >> w;
    
    vector<pair<int64_t, int>> p(n);
    
    for (int i = 0; i < n; i++)
    {
	cin >> p[i].first;
	p[i].second = i + 1;
    }
    
    sort(p.begin(), p.end());
    
    int64_t sum = 0;
    
    for (int i = 0; i < n; i++)
    {
	if(p[i].first*2 >= w && p[i].first <= w){
	    cout << "1\n";
	    cout << p[i].second << "\n";
	    return;
	}
    }
    
    vector<int> ans;
    
    for (int i = 0; i < n; i++)
    {
	sum += p[i].first;
	ans.push_back(p[i].second);
	if(sum <= w && sum*2 >= w){
	    cout << ans.size() << "\n";
	    for(auto x: ans){
		cout << x << " ";
	    }
	    cout << "\n";
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

    while(testCase-->0) solve(testCase);
    
    return 0;
}	
