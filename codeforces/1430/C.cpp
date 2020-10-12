#include <bits/stdc++.h>
 
using namespace std;

void solve(){
	int n;
	cin >> n;
	
	priority_queue<int> q;
	
	for (int i = 0; i < n; i++)
		q.push(i+1);
		
	vector<pair<int,int>> ans;
	while(q.size()){
		int x,y,z;
		x = q.top();
		q.pop();
		y = q.top();
		q.pop();
		if(q.size() == 0){
			cout << (x+y+1)/2 << "\n";
			ans.push_back({x,y});
			break;
		}
		z = q.top();
		q.pop();
		if(x%2 == y%2){
			ans.push_back({x,y});
			q.push(z);
			q.push((x+y)/2);
		} else if(x%2 == z%2){
			ans.push_back({x,z});
			q.push(y);
			q.push((x+z)/2);
		}else if(z%2 == y%2){
			ans.push_back({z,y});
			q.push(x);
			q.push((z+y)/2);
		} else { 
			assert(false);
		}
	}
	
	for(auto hola: ans){
		cout << hola.first << " " << hola.second << "\n";
	}
	
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	int tt = 1;
	cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}
