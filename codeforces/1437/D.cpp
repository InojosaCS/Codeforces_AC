#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    
    for (int i = 0; i < n; i++)
	cin >> a[i];
    
    if(n == 1){
	cout << "0\n";
	return;
    }
    
    int ans = 0, start = 1;
    vector<int> h(n+1, 0);
    h[0] = 1;
    
    while(start < n){
	int i = start;
	while(i < n-1 && a[i] < a[i+1]){
	    i++;
	    h[ans+1]++;
	}
	h[ans+1]++;
	h[ans]--;
	if(h[ans] == 0) ans++;
	start = i+1;
	//cout << start << " " << ans << " " << h[ans] << "\n";
    }    
    
    for (int i = 0; i < n+1; i++)
    {
	if(h[i]) ans = i;
    }
    
    cout << ans << "\n";
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int32_t tt = 1;
    cin >> tt;

    while(tt-->0) solve();

    return 0;
}
