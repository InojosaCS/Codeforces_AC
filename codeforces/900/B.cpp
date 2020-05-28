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
#define deb(i) cout << "Aqui " << (ll) i << "\n";
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	
	ll a,b,c,cnt=0;
	cin >> a >> b >> c;
	map <pair<int,int>,bool> visited;
	while(true){
		cnt++;
		a *= 10;
		if(visited[{a,b}]){
			cnt=-1;
			break;
		}
		visited[{a,b}]=1;
		ll foo = a/b;
		a %= b;
		if(c==foo) break;
	}
	
	cout << cnt << "\n";
	return 0;

}
