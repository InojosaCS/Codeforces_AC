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
	
	int n;
	cin >> n;
	vi a(n), b(n);
	map<int,int> pos;
	vi count(n+1,0);
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		pos[b[i]]=i+1;
	}
	
	for (int i = 0; i < n; i++)
	{
		if(pos[a[i]]<i+1){
			count[n-((i+1)-pos[a[i]])]++;
		}else{
			count[pos[a[i]]-(i+1)]++;
		}
	}
	
	cout << *max_element(all(count)) << "\n";
	//cout<<double(clock()-T)/CLOCKS_PER_SEC<<'\n';
	return 0;
 
}
