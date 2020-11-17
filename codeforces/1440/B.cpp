#include <bits/stdc++.h>
 
using namespace std;

#define int int64_t

void solve(){
    int64_t n, k;
    cin >> n >> k;
    vector<int> a(n*k);
    
    for (int i = 0; i < n*k; i++)
    {
	cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    int64_t sum = 0;
    int mid = n - (n+1)/2, t = 0;
    
    for (int i = mid; i < n*k && t < k; i+=mid+1)
    {
	sum += a[i];
	//cout << i << " \n"[i == n*k - 1];
	t++;
    }
    
    cout << sum << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int32_t tt = 1;
    cin >> tt;

    while(tt-->0) solve();
    
    return 0;
}	
