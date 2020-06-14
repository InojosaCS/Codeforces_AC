#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
typedef vector<ii> vii;
 
#define solve imAwesome
#define for0(i,n) for(int i=0; i<(int)n; i++)
#define forn(i,n) for(int i=1; i<=(int)n; i++)
#define pb push_back
#define sz(s) (ll) s.size()
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(),x.end()
#define endl cout << "\n";
#define deb(i) cout << "Aqui " << (ld) i << "\n";
#define pi 3.141592653589793238462643383279502884197169399375105820974944592307816406286L

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	
	int t;
	cin >> t;
	while(t--){
		string s;
		cin  >> s;
		int n = sz(s);
		vector<int> p,i,ans;
		
		for(int k=0; k<n;k++){
			if((s[k]-'0')%2)
				i.pb(s[k]-'0');
			else
				p.pb(s[k]-'0');
		}
		
		i.pb(11);
		p.pb(11);
		
		int x=0,y=0;
		
		while(x!=sz(i)-1 || y!=sz(p)-1){
			if(i[x]<p[y]){
				ans.pb(i[x]);
				x++;
			}else{
				ans.pb(p[y]);
				y++;
			}
		}
		for(int k=0; k<n; ++k){
			cout << ans[k];
		}
		endl
	}
	return 0;

}
