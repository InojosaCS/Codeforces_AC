#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
 
#define solve imAwesome
#define for0(i,n) for(int i=0; i<(int)n; i++)
#define forn(i,n) for(int i=1; i<=(int)n; i++)
#define pb push_back
#define f first
#define s second
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define all(x) x.begin(),x.end()
#define sz(s) (ll) s.size()
#define endl cout << "\n";
#define deb(i) cout << "Aqui " << (ld) i << "\n";
//#define int long long 

int main(){
	//auto T=clock();
	
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.precision(20);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<char> a(n,'*'),b(n,'*');
		bool helper = false;
		for(int i=0; i<sz(s); i++){
			if(s[i]=='1' && !helper){
				a[i]='1';
				b[i]='0';
				helper = 1;
			}else if(!helper && s[i]=='2'){
				a[i]='1';
				b[i]='1';
			}else if(!helper && s[i]=='0'){
				a[i]='0';
				b[i]='0';
			}else{
				a[i]='0';
				b[i]=s[i];
			}
		}
		for(auto x: a){
			cout << x;
		}
		endl
		for(auto x: b){
			cout << x;
		}
		endl
	}
	//cout<<double(clock()-T)/CLOCKS_PER_SEC<<'\n';
	return 0;
 
}
