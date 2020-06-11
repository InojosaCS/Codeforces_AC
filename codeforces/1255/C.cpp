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
	map <tuple<int,int,int>,int> myMap;
	vi degree(n+1,0);
	vector<tuple<int,int,int>> triples;
	
	for (int i = 0; i < n-2; i++)
	{
		vi a(3);
		cin >> a[0] >> a[1] >> a[2];
		sort(all(a));
		triples.pb({a[0],a[1],a[2]});
		
		if(myMap[{a[1],a[0],1}])
			myMap[{a[1],a[0],0}]=myMap[{a[0],a[1],0}]=a[2];
		else
			myMap[{a[1],a[0],1}]=myMap[{a[0],a[1],1}]=a[2];
		
		if(myMap[{a[2],a[0],1}])
			myMap[{a[2],a[0],0}]=myMap[{a[0],a[2],0}]=a[1];
		else
			myMap[{a[2],a[0],1}]=myMap[{a[0],a[2],1}]=a[1];
		
		if(myMap[{a[2],a[1],1}])
			myMap[{a[2],a[1],0}]=myMap[{a[1],a[2],0}]=a[0];
		else
			myMap[{a[2],a[1],1}]=myMap[{a[1],a[2],1}]=a[0];
		
		degree[a[0]]++;
		degree[a[1]]++;
		degree[a[2]]++;
	}
	
	tuple<int,int,int> first;
	
	for(auto X: triples){
		int a,b,c;
		tie(a,b,c)=X;
		if(degree[a]==1){
			if(degree[b]==2)
				first={a,b,c};
			else
				first={a,c,b};
		}else if(degree[b]==1){
			if(degree[a]==2)
				first={b,a,c};
			else
				first={b,c,a};
		}else if(degree[c]==1){
			if(degree[a]==2)
				first={c,a,b};
			else
				first={c,b,a};
		}
	}
	
	vi ans;
	int x,y,z;
	tie(x,y,z)=first;
	ans.pb(x);
	ans.pb(y);
	
	while(degree[z]!=1){
		ans.pb(z);
		int temp_y = y;
		int temp_z = z;
		z = myMap[{y,z,0}]==x ? myMap[{y,z,1}] : myMap[{y,z,0}];
		y = temp_z;
		x = temp_y;
	}
	ans.pb(z);
	for(auto X: ans)
		cout << X << " ";
	
	endl
	//cout<<double(clock()-T)/CLOCKS_PER_SEC<<'\n';
	return 0;
 
}
