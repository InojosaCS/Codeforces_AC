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
	int q,x;
	cin >> q >> x;
	vll val(x,0ll), arr(q);
	bitset<10000001> visited;
	
	for (int i = 0; i < q; i++)
	{
		ll a;
		cin >> a;
		arr[i]=(a%x)+x*(val[(a%x)]);
		//visited[arr[i]]=1;
		val[a%x]++;
	}
	ll mn = 0;
	for (int i = 0; i < q; i++)
	{
		if(arr[i]<1e7) visited[arr[i]]=1;
		while(visited[mn])
			mn++;
		cout << mn << "\n";
	}
	
	
	//cout<<double(clock()-T)/CLOCKS_PER_SEC<<'\n';
	return 0;
 
}
