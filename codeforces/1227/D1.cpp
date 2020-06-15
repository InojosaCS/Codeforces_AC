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
	
	int n,m;
	cin >> n;
	vector<int> a(n);
	
	for(int i=0; i<n; i++)
		cin >> a[i];
	
	vector<int> b=a;
	sort(all(b), greater<int>());
	cin >> m;
	
	while(m--){
		int k,pos;
		cin >> k >> pos;
		map<int,int> needed;
		
		for (int i = 0; i < k; i++)
		{
			needed[b[i]]++;
		}
		
		int cnt = 0, ans;
		
		for (int i = 0; i < n; i++)
		{
			if(needed[a[i]] && cnt<pos){
				needed[a[i]]--;
				cnt++;
				ans = a[i];
			}
		}
		cout << ans << "\n";
	}
		
	cout << "\n";
	return 0;

}
