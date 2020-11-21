#include <bits/stdc++.h> 
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")

using namespace std; 

void solve(){
    int64_t  d,k;
    cin >> d >> k;
    
    string ans = "";
    
    for (int64_t i = 0; i < d + 2; i++)
    {
        if(k*k*i*i*2 > d*d){
            int64_t prev = i-1LL;
            //cout << i << ": " << k*k*i*i*2 << " " << d*d << "\n";
            //cout << "aja: " << (d*d - prev*k*prev*k) << " - " << k*k*prev*prev << " == " << k*k << "\n";

            //if((d*d - prev*k*prev*k) - k*k*prev*prev >= k*k){
                
            if((k * (prev + 1) * k * (prev + 1)) + k*prev*k*prev <= d*d){
                ans = "Ashish";
            } else {
                ans = "Utkarsh";
            }
            break;
        }
    }
    
    cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int32_t tt = 1;
	cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}
