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
	int n, cnt=0;
	string s;
	cin >> n >> s;
	bool change = 1;
	
	while(change){
		int mx = -1;
		change = 0;
		for(int j=0; j<sz(s) && sz(s)>1; j++){
			if(j==0 && s[j]-'a'==s[j+1]-'a'+1)
				mx=max(mx, s[j]-'a');
			else if(j==sz(s)-1 && s[j]-'a'==s[j-1]-'a'+1)
				mx=max(mx, s[j]-'a');
			else if(s[j]-'a'==s[j+1]-'a'+1 || s[j-1]-'a'+1==s[j]-'a')
				mx=max(mx, s[j]-'a');
		}
		for(int j=0; j<sz(s); j++){
			if(j>0 && j<sz(s)-1 && (s[j]-'a'==mx) && ((s[j+1]-'a'==mx-1) || (s[j-1]-'a'==mx-1))){
				s.erase(s.begin()+j);
				cnt++;
				change=1;
				break;
			}else if(j==0 && s[j]-'a'==mx && s[j+1]-'a'==mx-1){
				s.erase(s.begin()+j);
				cnt++;
				change=1;
				break;
			}else if(j==sz(s)-1 && s[j]-'a'==mx && s[j-1]-'a'==mx-1){
				s.erase(s.begin()+j);
				cnt++;
				change=1;
				break;
			}
		}
	}
	cout << cnt << "\n";
	//cout<<double(clock()-T)/CLOCKS_PER_SEC<<'\n';
	return 0;
 
}
