#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int last = -1, ans = n;
    
    for (int i = 0; i < n; i++)
    {
        if(s[i] == 'B') last = i;
    }
    
    //ans = last + 1;
    int a = 0, b = 0;
    
    for (int i = 0; i <= last; i++)
    {
        if(s[i] == 'B' && a > 0){
            ans -= 2;
            a--;
        } else if(s[i] == 'B'){
            b++;
        } else if(s[i] == 'A'){
            a++;
        }
    }
    //cout << b << "\n";
    ans -= (b - b%2);
    cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	int tt = 1;
	cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}
