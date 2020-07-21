#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define debug(x) cout << (#x) << " is " << (x) << endl

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);
	
	int tt;
	cin >> tt;
	while(tt--){
		int n,m = 7;
		string s,t = "abacaba";
		cin >> n >> s;
		bool ans =  false;
		int cnt = 0;
		
		for (int x = 0; x+m <= n; x++)
		{
			bool temp = true;
			for (int j = x; j < x+m && temp; j++)
				temp = (t[j-x]==s[j]);
			if(temp)
				cnt++;
		}
		
		if(cnt>1){
			cout << "NO\n";
		}else if(cnt==1){
			cout << "YES\n";
			for (int i = 0; i < n; i++)
				cout << (s[i]=='?' ? 'z' : s[i]);
			cout << "\n";	
		}else{
			
			for (int i = 0; i+m <= n; i++)
			{
				bool temp = true;
				for (int j = i; j < i+m && temp; j++)
					temp = (s[j]=='?' || t[j-i]==s[j]);
					
				if(temp){
					string copy = s;
					for (int j = i; j < i+m; j++)
						copy[j] = t[j-i];
					
					cnt = 0;
		
					for (int x = 0; x+m <= n; x++)
					{
						bool temp2 = true;
						for (int j = x; j < x+m && temp2; j++)
							temp2 = (t[j-x]==copy[j]);
						if(temp2)
							cnt++;
					}
					
					if(cnt==1){
						for (int j = i; j < i+m; j++)
							s[j] = t[j-i];
						ans = true;
						break;
					}
				}
			}
			
			if(ans){
				cout << "YES\n";
				for (int i = 0; i < n; i++)
					cout << (s[i]=='?' ? 'z' : s[i]);
				cout << "\n";
			}else{
				cout << "NO\n";
			}
		}
		
	}
	return 0;
}
