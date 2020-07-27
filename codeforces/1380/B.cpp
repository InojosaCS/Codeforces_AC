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
		string ss;
		cin >> ss;
		vector<char> ans;
		int r,p,s;
		r = p = s = 0;
		
		for(char c: ss){
			if(c=='R') ++r;
			else if(c=='S') s++;
			else p++;
		}
		
		for (int i = 0; i < sz(ss); i++)
		{
			if(max({r,p,s}) == r){
				ans.push_back('P');
			} else if(max({r,p,s}) == s){
				ans.push_back('R');
			} else {
				ans.push_back('S');
			}
		}
		
		for(char c: ans) cout << c;
		cout << "\n";
	}

	return 0;
}
