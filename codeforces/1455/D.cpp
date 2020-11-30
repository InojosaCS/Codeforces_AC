#include <bits/stdc++.h> 
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")

using namespace std; 

#define int int64_t 

void solve(int test) { 
    int n, x;
    cin >> n >> x;
    
    vector<int> a(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    int r = -1, cnt = 0;
    
    for (int i = 0; i + 1 < n; i++)
    {
        if(a[i] > a[i+1]) r = i;
    }
    
    for (int i = 0; i <= r; i++)
    {
        if(a[i] > x){
            swap(a[i], x);
            cnt++;
        }
    }
    
    //cout << "TEST: " << test << "  ************   " << cnt << "\n";
    
    vector<int> v = a;
    sort(v.begin(), v.end());
    
    if(a != v){
        cout << "-1\n";
        return;
    }
    cout << cnt << "\n";
    assert(a==v);
    
    //for (int i = 0; i < n; i++)
    //{
        //cout << a[i] << " \n"[i==n-1];
    //}
    
    
}
    
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    
	int32_t tt = 1;
	cin >> tt;

	while(tt-->0) solve(tt);
	
	return 0;
}
