#include <bits/stdc++.h> 

using namespace std; 

void solve(){
    int n, m;
    cin >> n >> m;
    int a[n+1][m+1];
    int pref[n+1][m+1];
    
    for (int i = 0; i < n+1; i++)
	for(int j = 0; j < m+1; j++)
	    pref[i][j] = a[i][j] = 0;
    
    for (int i = 0; i < n; i++)
    {
	for(int j = 0; j < m; j++){
	    char x;
	    cin >> x;
	    if(x == '*') a[i+1][j+1] = 1;
	    else a[i+1][j+1] = 0;
	}
    }
 
    for (int i = 1; i < n+1; i++)
	for(int j = 1; j < m+1; j++)
	    pref[i][j] = a[i][j] + pref[i][j-1];
  
    //for (int i = 1; i < n+1; i++)
	//for(int j = 1; j < m+1; j++)
		//cout << pref[i][j] << " \n"[j==m];
    
    int ans = 0;
    
    for(int i = 1; i <= n; i++){
	for(int j = 1; j <= m; j++){
	    int l = j, r = j, need = 1;
	    for(int k = i; k <= n; k++){
		if(l -1 < 0 || r > m || pref[k][r] - pref[k][l-1] != need) break;
		ans++; r++; l--; need += 2;
	    }
	}
    }
    
    cout << ans << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int32_t testCase = 1;
    cin >> testCase;

    while(testCase-->0) solve();
    
    return 0;
}	
