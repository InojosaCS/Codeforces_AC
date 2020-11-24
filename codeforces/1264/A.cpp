#include <bits/stdc++.h> 
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")

using namespace std; 

void solve(){
    int n;
    cin >> n;
    
    vector<int> p(n+1, -3);
    map<int64_t, int> cnt;
    
    for (int i = 0; i < n; i++)
    {
        cin >> p[i+1];
        cnt[p[i+1]]++;
    }
    
    int h = n/2;
    while(h >= 0 && p[h] == p[h+1]) h--;
    int d = cnt[p[1]] * 2 + 2;
    int g = cnt[p[1]];
    while(d <= h && p[d] == p[d-1]) d++;
    int s = d - g - 1;
    int b = h - (g+s);
    
    //cout << h << ": " << g << " " << s << " " << b << "\n";
    if(g < s && g < b) cout << g << " " << s << " " << b << "\n";
    else cout << "0 0 0\n";
    
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    //freopen("output.txt", "w", stdout);
    
	int32_t tt = 1;
	cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}
