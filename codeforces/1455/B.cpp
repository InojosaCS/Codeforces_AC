#include <bits/stdc++.h> 
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")

using namespace std; 

#define int int64_t 

void solve() { 
    int x;
    cin >> x;
    int sum = 0;
    
    for (int i = 0; i <= x; i++)
    {
        sum += i;
        if(sum >= x){
            if(sum == x + 1) cout << i+1 << "\n";
            else cout << i << "\n";
            return;
        }
         //else if(sum > x){
            //cout << i + 1 << "\n";
            //return;
        //}
    }
    
}
    
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    
	int32_t tt = 1;
	cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}
