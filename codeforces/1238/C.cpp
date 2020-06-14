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
	
	int q;
	cin >> q;
	while(q--){
		int h,n;
		cin >> h >> n;
		vi p(n);
		map<int,bool> visited;
		
		for(int i=0; i<n; i++)
		{
			cin >> p[i];
			visited[p[i]]=true;
		}
		visited[0]=1;	
		int sum = 0;
		
		if(n>1){
				
			int current = p[1]+1;
		
			for(int i=1; i<n; i++)
			{
				//cout << current << " " << i << " " << p[i] << "\n";
				if(current <= 2){
					break;
				}
				if(current <= p[i]){
					continue;
				}
				if(current > p[i] + 1){
					current = p[i]+1;
				}
				if(visited[current - 1] && visited[current-2]){
					current -= 2;
				}else{
					current-=2;
					sum++;
				}
			}
		}
	
		
		cout << sum << "\n";
	}
	
	return 0;

}
