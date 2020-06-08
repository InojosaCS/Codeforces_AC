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
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int graph[26][2];
		vector<char> ans;
		vector<bool> visited(26,0);
		string abc = "qwertyuiopasdfghjklzxcvbnm";
		sort(all(abc));
		bool valid = true;
		
		for (int i = 0; i < 26; i++)
			graph[i][0]=graph[i][1]=-1;
		
		//graph[s[0]-'a'][1]=s[1]-'a';
		ans.pb(s[0]);
		visited[s[0]-'a']=1;
		
		for (int i = 1; i < sz(s); i++)
		{	
			
			if(graph[s[i-1]-'a'][0]==s[i]-'a' || graph[s[i-1]-'a'][1]==s[i]-'a'){
				continue;
			}else if(graph[s[i-1]-'a'][1]==-1 && !visited[s[i]-'a']){
				ans.insert(ans.begin(), s[i]);
				graph[s[i-1]-'a'][1]=s[i]-'a';
				graph[s[i]-'a'][0]=s[i-1]-'a';
				visited[s[i]-'a']=1;
			}else if(graph[s[i-1]-'a'][0]==-1 && !visited[s[i]-'a']){
				ans.insert(ans.end(), s[i]);
				graph[s[i-1]-'a'][0]=s[i]-'a';
				graph[s[i]-'a'][1]=s[i-1]-'a';
				visited[s[i]-'a']=1;
			}else{
				valid=false;
				break;
			}
		}
			
		if(valid){
			cout << "YES\n";
			for(auto c: ans)
				cout << c;
			for(int i = 0; i < sz(abc); i++)
				if(!visited[i])
					cout << abc[i];
			endl
		}else{
			cout << "NO\n";
		}
		
	}
	
	//cout<<double(clock()-T)/CLOCKS_PER_SEC<<'\n';
	return 0;
 
}
