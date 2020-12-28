#include <bits/stdc++.h> 
 
using namespace std; 

void solve(){
    int n, k;
    cin >> n >> k;
    
    vector<int> h(n);
    
    for (int i = 0; i < n; i++)
    {
	cin >> h[i];
    }
    
    int top = h[0] + k;
    int base = h[0];
    string ans = "YES\n";
    
    for (int i = 1; i < n; i++)
    {
	base = max(0, base - (k - 1));
	int64_t bottom = (i == n-1) ? h[i] : h[i] + k - 1;
	//cout << base << " " << bottom << "\n";
	
	if(base > bottom) ans = "NO\n";// cout << i << ": " << base << " first " << bottom << " \n";
	if(top <= h[i]) ans = "NO\n";// cout << i << ": " << top << " first " << h[i] << " \n";
	top = min(top + k - 1, h[i] + 2 * k - 1);
	base = max(base, h[i]);
    }
    
    
    /*
     *
     * 1
     * 1 1 1
     * # 1 1
     * #   #
     * #   #
    */
    
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
