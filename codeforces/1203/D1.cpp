#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
 
#define solve imAwesome
#define for0(i,n) for(int i=0; i<(int)n; i++)
#define forn(i,n) for(int i=1; i<=(int)n; i++)
#define pb push_back
#define f first
#define s second
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define all(x) x.begin(),x.end()
#define sz(s) (ll) s.size()
#define endl cout << "\n";
#define deb(i) cout << "Aqui " << (ld) i << "\n";
//#define int long long 

bool isSubSequence(string str1, string str2, int m, int n) 
{ 
   int j = 0;
   for (int i=0; i<n&&j<m; i++) 
       if (str1[j] == str2[i]) 
         j++; 
  
   return (j==m); 
} 

int main(){
	//auto T=clock();
	
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.precision(20);

	string s,t;
	cin >> s >> t;
	ll n = sz(s), m = sz(t);
	vll ans;
	ans.pb(0);
	
	for (int i = 0; i < n; i++)
	{
		string helper = s;
		for (int j = i; j < n; j++)
		{
			helper[j] = '*';
			if(isSubSequence(t, helper, m, n)){
				ans.pb(j-i+1);
			}
		}
		
	}
	
	cout << *max_element(all(ans)) << "\n";
	//cout<<double(clock()-T)/CLOCKS_PER_SEC<<'\n';
	return 0;
 
}
