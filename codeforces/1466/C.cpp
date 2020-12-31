#include <bits/stdc++.h> 
 
using namespace std; 

void solve(int test){
    string s;
    cin >> s;

    int n = s.size();
    int ans = 0;
    
    for (int i = 1; i < n; i++)
    {
	if(s[i] == s[i-1] || (i > 1 && s[i] == s[i-2])){
	    s[i] = '@';
	    ans++;
	}
    }
    
    cout << ans << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int32_t testCase = 1;
    cin >> testCase;

    while(testCase-->0) solve(testCase);
    
    return 0;
}	
