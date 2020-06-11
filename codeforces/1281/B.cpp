#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
 
#define solve imAwesome
#define for0(i,n) for(int i=0; i<(int)n; i++)
#define forn(i,n) for(int i=1; i<=(int)n; i++)
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define all(x) x.begin(),x.end()
#define sz(s) (ll) s.size()
#define endl cout << "\n";
#define deb(i) cout << "Aqui " << (ld) i << "\n";
#define pi 3.141592653589793238462643383279502884197169399375105820974944592307816406286L
//#define int long long 

int main(){
	//auto T=clock();
	
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.precision(20);
	
	int t;
	cin >> t;
	while(t--){
		string x,y;
		cin >> x >> y;
		string a = x;
		/*vector <char> x,y;
		
		for(auto c: a)
			x.pb(c);
		for(auto c: b)
			y.pb(c);
		*/
		vector <pair<char,int>> mn(sz(a));
		mn[sz(a)-1]={x[sz(a)-1], sz(a)-1};

		for(int i=sz(a)-2; i>0; i--){
			if(x[i]<mn[i+1].first){
				mn[i]={x[i], i};
			}else{
				mn[i]={mn[i+1].first, mn[i+1].second};
			}
		}
		
		bool cambio = false;
		
		for (int i = 0; i < sz(a)-1; i++)
		{
			if(x[i]<y[i] || cambio){
				break;
			}else if(x[i]==y[i] && mn[i+1].first<y[i]){
				char temp = x[i];
				x[i]=mn[i+1].first;
				x[mn[i+1].second] = temp;
				cambio = true;
			}else if(x[i]>y[i] && mn[i+1].first<=y[i]){
				char temp = x[i];
				x[i]=mn[i+1].first;
				x[mn[i+1].second] = temp;
				cambio = true;
			}
		}
		
		if(x<y)
			cout << x << "\n";
		else
			cout << "---\n";
	}
	//cout<<double(clock()-T)/CLOCKS_PER_SEC<<'\n';
	return 0;
 
}
