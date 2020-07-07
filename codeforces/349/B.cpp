#include <bits/stdc++.h>
 
using namespace std;

int main(){
	
	long long v;
	cin >> v;
	vector<pair<long long, long long>> a;
	vector<long long> cost(10);
	
	for (int i = 1; i < 10; i++)
	{
		long long x;
		cin >> x;
		a.push_back({x,-i});
		cost[i]=x;
	}
	
	sort(a.begin(), a.end());
	
	for (int i = 0; i < 9; i++)
		a[i].second = -a[i].second;

	int sz = v/a[0].first, mn = a[0].second;
	v = v%a[0].first;

	vector<int> ans(sz, mn);
	int current = 9;

	for (int i = 0; i < sz; ++i)
	{
		v += cost[ans[i]];
		//cout << v << " " << cost[current] << " " << current << "\n";
		while(cost[current]>v && current>=a[0].second){
			current--;
		}
		
		if(v>=cost[current]){
			ans[i] = current;
			v -= cost[current];
		}else{
			v -= cost[ans[i]];
		}
	}
	
	sort(ans.begin(), ans.end(), greater<int>());

	if(ans.size()){
		for(auto x: ans)
			cout << x;
		
		cout << "\n";
	}else{
		cout << "-1\n";
	}
	return 0;
}
