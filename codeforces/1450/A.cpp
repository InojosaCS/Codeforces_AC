#include <bits/stdc++.h> 
 
using namespace std; 

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    cout << s << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int32_t testCase = 1;
    cin >> testCase;

    while(testCase-->0) solve();
    
    return 0;
}	
