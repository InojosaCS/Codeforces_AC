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
		int n,cnt=0;
		cin >> n;
		vi a(n),b(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
			cnt+=b[i];
		}
		bool ans = 1;
		for (int i = 0; i < n-1; i++)
		{
			if(a[i]>a[i+1]){
				ans = false;
				break;
			}
		}
		if(ans || (cnt && cnt!=n)){
			cout << "Yes\n";
		}else{
			cout << "No\n";
		}
	}
	//cout<<double(clock()-T)/CLOCKS_PER_SEC<<'\n';
	return 0;
 
}
