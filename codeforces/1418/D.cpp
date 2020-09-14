#include <bits/stdc++.h>
 
using namespace std;

void solve(){
	int64_t n,q,xi;
	cin >> n >> q;
	set<int64_t> s;
	
	for (int i = 0; i < n; i++)
	{
		cin >> xi;
		s.insert(xi);
	}
	
	int64_t prev = *s.begin();
	map<int64_t, int64_t> cnt;
	
	for(int64_t x: s){
		if(x == *s.begin()) continue;
		cnt[x-prev]++;
		prev = x;
	}
	
	cnt[0] = 1e8;
	int64_t current = cnt.rbegin() -> first, c = *(s.rbegin()), b = *(s.begin());
	cout << c - b - current << "\n";
	
	for (int i = 0; i < q; i++)
	{
		int64_t t,x,l = 0,r = 0;
		cin >> t >> x;
		
		 //left
		if(s.size()){
			auto smaller = s.lower_bound(x); 
			if (smaller != s.begin()){ 
				--smaller;
				l =  *(smaller); 
			}
			
			//left
			auto greater = s.upper_bound(x); 
			if (greater != s.end()){
				r =  *(greater);
			}
		}
		
		if(t == 1){
			if(l && r){
				cnt[r-l]--;
				if(cnt[r-l] == 0) cnt.erase(cnt.find(r-l));
			}
			if(l) cnt[x-l]++;
			if(r) cnt[r-x]++;
			s.insert(x);
		}else{
			if(l && r) cnt[r-l]++;
			if(l){
				cnt[x-l]--;
				if(cnt[x-l] == 0) cnt.erase(cnt.find(x-l));
			}
			if(r){
				cnt[r-x]--;
				if(cnt[r-x] == 0) cnt.erase(cnt.find(r-x));
			}
			s.erase(x);
		}
		
		if(s.size() > 2) current = cnt.rbegin() -> first, c = *(s.rbegin()), b = *(s.begin());
		else current = b = c = 0LL;
		cout << c - b - current << "\n";
	
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(20);	
		
	int t = 1;
	//cin >> t;

	while(t--) solve();
	
	return 0;
}
