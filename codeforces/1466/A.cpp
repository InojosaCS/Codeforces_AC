#include <bits/stdc++.h> 
 
using namespace std; 

void solve(int test){
    int n;
    cin >> n;
    
    vector<int> a(n);
    
    for (int i = 0; i < n; i++)
    {
	cin >> a[i];
    }
    
    set<int> s;
    
    for (int i = 0; i < n; i++)
    {
	for (int j = i+1; j < n; j++)
	{
	    s.insert(abs(a[i] - a[j]));
	}
    }
    
    cout << s.size() << "\n";
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int32_t testCase = 1;
    cin >> testCase;

    while(testCase-->0) solve(testCase);
    
    return 0;
}	
