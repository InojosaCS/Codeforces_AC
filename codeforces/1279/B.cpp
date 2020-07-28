#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl
//#define int long long



int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);

	int tt;
	cin >> tt;
	while(tt--){
		ll n,s;
		cin >> n >> s;
		ll a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		
		ll mx = 0ll, cum = 0ll, index = 0, ans = 0;
		
		for (int i = 0; i < n; i++)
		{
			
			if (a[i] > mx) ans = i+1;
			mx = max(mx, a[i]);
			if(cum + a[i] > s){
				break;
			}
			index++;
			cum += a[i];
		}
		
		cum = -mx; ll dos = 0ll;
	
		for (int i = 0; i < n; i++)
		{
			if(cum + a[i] > s){
				break;
			}
			dos++;
			cum += a[i];
		}
		dos--;
		if(dos>=index){
			cout << ans << "\n";
		}else{
			cout << "0\n";
		}
	}
    return 0;
}
