#include <bits/stdc++.h>
 
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define debug(x) cout << (#x) << " is " << x << "\n"

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int n;
	cin >> n;
	int a[n];
	set<int> s;
	map<int,int> dp;

	for (int i = 0; i < n; ++i)
	{	
		cin >> a[i];
		dp[a[i]] = 1;
	}
	int last = a[0], mx = 1;

	for (int i = 0; i < n; ++i)
	{
		if(s.count(a[i]-1)){
			dp[a[i]] = dp[a[i]-1]+1;
			if(dp[a[i]]>mx){
				mx = dp[a[i]];
				last = a[i];
			}
		}
		s.insert(a[i]);
	}
	
	int current = last - mx + 1;
	vector<int> ans;
	//cout << last << " " << current << " " << mx << "\n";
	for (int i = 0; i < n; ++i)
	{
		if(a[i]==current && current<=last){
			ans.push_back(i+1);
			current++;
		}
	}

	cout << mx << "\n";
	for(auto x: ans)
		cout << x << " ";
	cout << "\n"; 
	return 0;
}
