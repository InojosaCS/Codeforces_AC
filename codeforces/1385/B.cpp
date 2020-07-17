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
		vector<int> ans;
		std::vector<bool> visited(100, 0);
		for (int i = 0; i < 2*n; ++i)
		{
			int a;
			cin >> a;
			if(visited[a]){
				ans.push_back(a);
			}else{
				visited[a]=1;
			}
		}
		for(auto x: ans){
			cout << x << " ";
		}
		cout << "\n";
	}
	return 0;
}