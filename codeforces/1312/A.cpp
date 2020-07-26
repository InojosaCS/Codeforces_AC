#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);

	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		if(n%m==0) cout << "YES\n";
		else cout << "NO\n";
		
	}
	return 0;
}
