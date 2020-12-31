#include <bits/stdc++.h> 
 
using namespace std; 

void solve(int test){
    int n;
    cin >> n;
    
    vector<int> a(n);
    map<int,bool> v;
    
    for (int i = 0; i < n; i++)
    {
	cin >> a[i];
    }
    
    set<int> s;
    
    for (int i = 0; i < n; i++)
    {
	if(v[a[i]]){
	    s.insert(a[i]+1);
	    v[a[i]+1] = 1;
	} else {
	    s.insert(a[i]);
	    v[a[i]] = 1;
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
