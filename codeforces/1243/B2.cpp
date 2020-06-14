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
	
	int k;
	cin >> k;
	
	while(k--){
		int n;
		cin >> n;
		string s,t;
		cin >> s >> t;
		vector<bool> visited(n,false);
		vector<int> parityTable(26,0);
		
		for (int i = 0; i < n; i++)
		{
			parityTable[t[i]-'a']++;
			parityTable[s[i]-'a']++;
			if(s[i]==t[i]){
				visited[i]=true;
			}
		}
		
		bool ans = true;
		
		for(int i=0; i<26; i++)
			if(parityTable[i]%2)
				ans = false;
				
		if(ans){
			vector<pair<int,int>> pairs;
			
			for (int i = 0; i < n-1; i++)
			{
				if(s[i]!=t[i]){
					bool find = false;
					
					for(int j=i+1; j<n; j++){
						if(!visited[j] && s[i]==s[j]){
							s[j] = t[i];
							t[i] = s[i];
							find = true;
							pairs.pb({(j+1), (i+1)});
							break;
						}
					}
					
					if(!find){
						for(int j=i+1; j<n; j++){
							if(!visited[j] && s[i]==t[j]){
								t[j] = s[j];
								s[j] = t[i];
								t[i] = s[i];
								pairs.pb({j+1,j+1});
								pairs.pb({j+1,i+1});
								break;
							}
						}
					}
				}
			}
			//cout << s << "\n" << t << "\n";
			if(s==t){
				cout << "Yes\n";
				cout << pairs.size() << "\n";
				for(auto par: pairs){
					cout << par.f << " " << par.s << "\n";
				}
			}else{
				cout << "No\n";
			}
		}else{
			cout << "No\n";
		}
		
		
	}
	
	return 0;

}
