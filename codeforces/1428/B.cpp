#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<char> a(n);
    
    int both = 0, anti = 0, clock = 0;
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] == '-') both++;
        if(a[i] == '>') clock++;
        if(a[i] == '<') anti++;
    }
    
    int ans = 0;
    
    for (int i = 0; i < n; i++)
    {
        if(a[i] == '-' || a[(i+1)%n] == '-'){
            ans++;
        } else if(a[i] == '<' && clock == 0){
            ans++;
        } else if(a[i] == '>' && anti == 0){
            ans++;
        } else if(a[(i+1)%n] == '<' && clock == 0){
            ans++;
        } else if(a[(i+1)%n] == '>' && anti == 0){
            ans++;
        }
    }
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
