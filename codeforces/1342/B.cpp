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
#define endl cout << "\n";
#define debug cout << "Aqui\n";
#define deb(i) cout << "Aqui " << (ld) i << "\n";
#define pi 3.141592653589793238462643383279502884197169399375105820974944592307816406286L

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	//auto T=clock();
	ll t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int a[2]={0,0};
		for (int i = 0; i < s.size(); i++) a[s[i]-'0']++;
		if(!a[0] || !a[1]){
			cout << s << "\n";
		}else{
			for (int i = 0; i < s.size(); i++) cout << "10";
			endl;
		}
		
	}
	//cout<<double(clock()-T)/CLOCKS_PER_SEC<<'\n';
	return 0;

}
