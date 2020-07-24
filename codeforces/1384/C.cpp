#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define debug(x) cout << (#x) << " is " << (x) << endl


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string a,b;
		cin >> a >> b;
		bool val = true;
		vector<vector<bool>> need(23, vector<bool>(23,false));
		
		for (int i = 0; i < n; i++)
		{
			if(a[i] > b[i]){
				val = false;
			}if(a[i] < b[i]){
				need[a[i]-'a'][b[i]-'a'] = true;
			}
		}
		
		if(!val){
			cout << "-1\n";
			continue;
		}
		
		int cnt = 0;
		
		for (int i = 0; i < 23; i++){
			int helper = -1;
			for (int j = 0; j < 23; j++){
				if(need[i][j]){
					helper = j;
					cnt++;
					break;
				}
			}
			if(helper>=0){
				for (int j = helper + 1; j < 23; j++){
					if(need[i][j]){
						need[helper][j] = true;
						need[i][j] = false;
					}
				}
				
			}
		}
		
		cout << cnt << "\n";
		
	}
	return 0;
}
