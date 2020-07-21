#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define debug(x) cout << (#x) << " is " << (x) << endl

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);
	
	int tt;
	cin >> tt;
	while(tt--){
		long long l,r,m;
		cin >> l >> r >> m;
		for (long long i = l; i < r+1; i++)
		{
			long long p = max(1ll, m/i);
			long long q = p+1;
			if( m-(r-l) <= i*p && i*p <= m){
				cout << i << " " <<  r << " " << r - (m-i*p);
				break;
			}else if(m <= i*p && i*p <= m + (r-l)){
				cout << i << " " <<  r - (i*p - m) << " " << r;
				break;
			}else if(m-(r-l) <= i*q && i*q <= m){
				cout << i << " " <<  r << " " << r - (m-i*q);
				break;
			}else if(m <= i*q && i*q <= m + r - l){
				cout << i << " " <<  r - (i*q - m) << " " << r;
				break;
			}
		}
		cout << "\n";
	}
	return 0;
}
