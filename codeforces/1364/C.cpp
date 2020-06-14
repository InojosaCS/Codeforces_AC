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
#define all(x) x.begin(),x.end()
#define endl cout << "\n";
#define deb(i) cout << "Aqui " << (ld) i << "\n";
#define pi 3.141592653589793238462643383279502884197169399375105820974944592307816406286L

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	
	int n;
	cin >> n;
	vector<int> a(n+1,0),b(n+1,-1);
	vector<bool> visited(1e6+3);

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	for (int i = 1; i <= n; ++i)
	{
		if(a[i-1]!=a[i])
		{
			b[i]=a[i-1];
			visited[a[i-1]]=1;
		}
	}
	
	visited[a[n]]=1;
	int mex = 0;
	
	for(int i=1; i<=n;++i){
		
		while(visited[mex])
			mex++;
		if(b[i]!=-1)
			continue;
		b[i]=mex;
		mex++;
		
	}
	for(int i=1; i<=n;i++)
		cout << b[i] << " ";
	cout << "\n";
	return 0;

}
