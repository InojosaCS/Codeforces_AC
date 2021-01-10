#include <bits/stdc++.h> 

using namespace std; 

void solve(int test){
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    reverse(s.begin(), s.end());
    
    int cnt = 0;
    
    for (int i = 0; i < n; i++)
    {
	if(s[i] != ')') break;
	cnt++;
    }
    
    if(n - cnt >= cnt) cout << "No\n";
    else cout << "Yes\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int32_t testCases = 1;
    cin >> testCases;
    
    while(testCases-->0) solve(testCases + 2);
    
    return 0;
}	
