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
	int n,m,k;
	cin >> n >> m >> k;
	vi px(k), py(k), finx(k), finy(k);
	for (int i = 0; i < k; i++)
	{
		cin >> px[i] >> py [i];
	}
	for (int i = 0; i < k; i++)
	{
		cin >> finx[i] >> finy[i];
	}
	
	cout << (n-1)+(m-1)+(n-1)*(m)+m -1<< "\n";
	for (int i=0; i < n-1; i++) cout << "D";
	for(int j=0; j<m-1; j++) cout << "L";
	for (int i = 0; i < n; i++)
	{
		for(int j=0; j<m-1; j++)
			if(i%2) cout << "L";
			else cout << "R"; 
		if(i!=n-1) cout << "U";
	}
	endl;
	//cout<<double(clock()-T)/CLOCKS_PER_SEC<<'\n';
	return 0;
 
}
