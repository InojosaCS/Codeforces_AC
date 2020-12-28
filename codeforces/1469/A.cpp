#include <bits/stdc++.h> 
 
using namespace std; 

void solve(){
    string s;
    cin >> s;
    
    int n = s.size();
    string ans  = "YES\n";
    
    if(n % 2 || s[0] == ')' || s[n-1] == '(') ans = "NO\n";
    cout << ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int32_t testCase = 1;
    cin >> testCase;

    while(testCase-->0) solve();
    
    return 0;
}	
