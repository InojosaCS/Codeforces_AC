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
#define f first
#define s second
#define mp make_pair
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define all(x) x.begin(),x.end()
#define sz(s) (ll) s.size()
#define endl cout << "\n";
#define debug cout << "Aqui\n";
#define deb(i) cout << "Aqui " << (ld) i << "\n";
#define pi 3.141592653589793238462643383279502884197169399375105820974944592307816406286L


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	//auto T=clock();
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vi arr(n);
		for(int i=0; i<n; i++)
			cin >> arr[i];
			
		sort(all(arr));
		int ans = -1;
		
		for(int i=1; i<=2048; i++){
			vi auxiliar;
			for(int j=0; j<n; j++){
				auxiliar.pb(arr[j] xor i);
			}
			
			sort(all(auxiliar));
			bool helper=true;
			if(sz(auxiliar)==sz(arr)){
				for(int k=0; k<sz(arr); k++){
					if(auxiliar[k]!=arr[k]){
						helper=false;
						break;
					}
				}
				if(helper){
					ans=i;
				}
			}
			if(sz(auxiliar)==sz(arr) && helper){
				break;
			}
		}
		cout << ans << "\n";
	}
	
	//cout<<double(clock()-T)/CLOCKS_PER_SEC<<'\n';
	return 0;
 
}
