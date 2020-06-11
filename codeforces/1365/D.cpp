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

bool visited[52][52];
char mat[52][52];
int visited_good=0;

void dfs(int x, int y){
	
	visited[x][y]=1;
	
	if(mat[x][y]=='G')
		{
			//cout << x <<  " " << y << " " << visited_good<< "\n";
			visited_good++;
		}
		
	for(int i=-1; i<=1; i+=2)
	{
		if(!visited[x+i][y] && mat[x+i][y]!='#'){
			dfs(x+i,y);
		}
	}
	for(int i=-1; i<=1; i+=2)
	{
		if(!visited[x][y+i] && mat[x][y+i]!='#'){
			dfs(x,y+i);
		}
	}
	return;
}

int main(){
	//auto T=clock();
	
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.precision(20);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		int good=0, bad=0;
		visited_good=0;
		
		for(int i=0; i<=51; i++)
		{
			for(int j=0;j<=51;j++)
			{
				mat[i][j]='#';
				visited[i][j]=1;
			}
		}
		
		for(int i=1; i<=n; i++)
		{
			for(int j=1;j<=m;j++)
			{	
				visited[i][j]=0;
				cin >> mat[i][j];
				if(mat[i][j]=='G'){
					good++;
				}
				if(mat[i][j]=='B'){
					bad++;
				}
			}
		}
		
		bool helper=true;
		
		for(int x=1; x<=n; x++)
		{
			for(int y=1;y<=m;y++)
			{	
				if(mat[x][y]=='B'){
					
					for(int i=-1; i<=1; i+=2)
					{
						if(mat[x+i][y]=='G'){
							helper = false;
							continue;	
						}
						if(mat[x+i][y]=='.')
							mat[x+i][y]='#';
					}
					for(int i=-1; i<=1; i+=2)
					{
						if(mat[x][y+i]=='G'){
							helper = false;
							continue;	
						}
						if(mat[x][y+i]=='.')
							mat[x][y+i]='#';
					}
				}
			}
		}
		
		if(mat[n][m]!='#')
			dfs(n,m);
		/*
		 * for(int i=1; i<=n; i++)
		{
			for(int j=1;j<=m;j++)
			{	
				cout << mat[i][j] ;	
			}
			endl
		}
		cout << good << " " << visited_good << " " << helper << "\n";
		*/
		if(good==0 || (good==visited_good && helper)){
			cout << "Yes\n";
		}else{
			cout << "No\n";
		}
		
	}
	//cout<<double(clock()-T)/CLOCKS_PER_SEC<<'\n';
	return 0;
 
}
