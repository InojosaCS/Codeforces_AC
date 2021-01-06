#include <bits/stdc++.h> 

using namespace std; 

void solve(int test){
    int64_t n, m;
    cin >> n >> m;
    
    vector<int> k(n);
    vector<int> c(m);
    
    for (int i = 0; i < n; i++)
	cin  >> k[i];
	
    for (int i = 0; i < m; i++)
	cin >> c[i];

    vector<pair<int,int>> p;
    
    for (int i = 0; i < n; i++)
    {
	p.push_back({c[k[i]-1], k[i]-1});
    }
    
    sort(p.rbegin(), p.rend());
    int index = 0;
    int64_t sum = 0;
    
    for (int i = 0; i < n; i++)
    {
	int x = p[i].first;
	int y = p[i].second;
	if(y >= index) sum += c[index++];
	else sum += c[y];
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
