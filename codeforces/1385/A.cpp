#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define debug(x) cout << (#x) << " is " << (x) << endl

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);
	
	int t;
	cin >> t;
	while(t--){
		long long x,y,z;
		cin >> x >> y >> z;
		long long mx = max({x,y,z});

		if((mx==x && mx==y)){
			cout << "YES\n";
			cout << mx << " " << z << " " << z << "\n";
		}else if((mx==z && mx==y)){
			cout << "YES\n";
			cout << mx << " " << x << " " << x << "\n";
		}else if((mx==x && mx==z)){
			cout << "YES\n";
			cout << mx << " " << y << " " << y << "\n";
		}else{
			cout << "NO\n";
		}
	}
	return 0;
}