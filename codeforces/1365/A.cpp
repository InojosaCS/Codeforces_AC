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
		int n,m;
		cin >> n >> m;
		int mat[n][m];
		
		for (int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++){
				cin >> mat[i][j];
			}
		}
		
		int r=0,c=0;
		for (int i = 0; i < n; i++)
		{
			bool ans = true;
			for(int j = 0; j < m; j++){
				if(mat[i][j])
					ans=false;
			}
			if(ans)
				r++;
		}
		
		for (int i = 0; i < m; i++)
		{
			bool ans = true;
			for(int j = 0; j < n; j++){
				if(mat[j][i])
					ans=false;
			}
			if(ans)
				c++;
		}
		if(min(r,c)%2==0){
			cout << "Vivek\n";
		}else{
			cout << "Ashish\n";
		}
	}
	//cout<<double(clock()-T)/CLOCKS_PER_SEC<<'\n';
	return 0;
 
}
