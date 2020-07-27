#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;

const long long M = 998244353ll;
	
ll expo(ll a, ll b){
	if(b==0) return 1ll;
	if(b==1) return a%M;
	else return expo(a*a%M, b/2)*(b%2 ? a : 1ll)%M;
}

ll inverseM(ll a){
	return expo(a, M-2);
}


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> p(n);
	
		for (int i = 0; i < n; i++)
			cin >> p[i];
		
		int x,y,z;
		bool ans = false;
		
		for (int i = 1; i < n-1; i++)
		{
			int l = -1, r = -1;
			for(int j = i; j<n; j++)
				if(p[j]<p[i])
					r = j;
			
			for(int j = 0; j<i; j++)
				if(p[j]<p[i])
					l = j;
			
			if(l>=0 && r>=0){
				ans = true;
				x = l+1;
				y = i+1;
				z = r+1;
				break;
			}
		}
		
		if(ans){
			cout << "YES\n" << x << " " << y << " " << z << "\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}
