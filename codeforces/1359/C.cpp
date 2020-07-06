#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<long long> vll;
 
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define sz(s) (ll) s.size()
#define deb(i) cout << "Aqui " << (ld) i << "\n";
 
int main(){
		
	int tt;
	cin >> tt;
	while(tt--){
		ld c,h,t;
		cin >> h >> c >> t;
		ll l=1ll, r = (ll)(1e12), ans, bs=(1e12);
		
		while(l<=r){
			ld mid = (ld)((l+r)/2ll);
			ld k1 = (mid*h + (mid-1.0)*c)/(2.0*mid - 1.0);
			ld k2 = ((mid+1.0)*h + (mid)*c)/(2.0*mid + 1.0); 
			ans = mid;
			
			if(k1>=t && k2<=t){
				//cout << mid << "fin\n";
				if(abs(k1-t)<=abs(k2-t)){
					ans = mid;
					bs = abs(k1-t);
				}else{
					ans = mid+1;
					bs = abs(k2-t);
				}
				//cout << mid << " " << k1 << " " << k2 << "\n";
				break;
			}
			
			if(k1<=t){
				r = mid-1ll;
			}else{
				l = mid+1ll;
			}
		}
		
		ld same = abs(t-(h+c)/(2.0));
		
		
		if(ans==1e12 || same<bs){
			cout << "2\n";
		}else{
			cout << ans+ans-1 << "\n";
		}
	}
	return 0;
}
