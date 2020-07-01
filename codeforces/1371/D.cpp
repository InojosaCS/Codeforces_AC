#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
 
#define for0(i,n) for(int i=0; i<(int)n; i++)
#define forn(i,n) for(int i=1; i<=(int)n; i++)
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define sz(s) (ll) s.size()
#define endl cout << "\n";
#define deb(i) cout << "Aqui " << (ld) i << "\n";
//#define int long long 


int main(){
	//auto T=clock();
	//cout<<double(clock()-T)/CLOCKS_PER_SEC<<'\n';
	
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	
	int t;
	cin >> t;
	while(t--){
		ll n,k,cum=0ll;
		cin >> n >> k;
		vector<vector<ll>> mat(n, vector<ll>(n,0));
		vector<pair<ll,ll>> order;
		
		for (int i = 0; i < n; i++)
			order.pb({0,i});
		
		for(auto x: order){
			int i = x.f;
			int j = x.s;
			int cnt = 0;
			while(cnt<n && cum<k){
				mat[i%n][j%n]=1;
				cum++;
				i++;
				j++;
				cnt++;
			}
		}
		
		vll rows(n), col(n);
		
		for(int i=0; i<n; i++){
			ll sum = 0ll;
			for(int j=0; j<n; j++){
				sum  += mat[i][j];
			}
			rows[i]=sum;
		}
		
		for(int i=0; i<n; i++){
			ll sum = 0ll;
			for(int j=0; j<n; j++){
				sum  += mat[j][i];
			}
			col[i]=sum;
		}
		
		ll rmx = *max_element(all(rows));
		ll rmn = *min_element(all(rows));
		ll cmx = *max_element(all(col));
		ll cmn = *min_element(all(col));
		
		cout << (rmx-rmn)*(rmx-rmn) + (cmx-cmn)*(cmx-cmn) << "\n";
		
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout << mat[i][j];
			}
			cout << "\n";
		}
	}
	return 0;
 
}
