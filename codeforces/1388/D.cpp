#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;
#define debv(v) for (int i = 0; i < sz(v); i++) cout << v[i] << " "; cout << "\n";



int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);	
	
	map<ll, vector<pair<ll,ll>>> g;
	ll n;
	cin >> n;
	vector<ll> a(n+1,0ll), b(n+1,0ll),cum(n+1,0ll);
	stack<pair<ll,ll>> s;
	queue<ll> q;
	
	for (int i = 0; i < n; i++) cin >> a[i+1];
	for (int i = 0; i < n; i++) cin >> b[i+1];
	for (int i = 0; i < n; i++)
	{
		g[b[i+1]].push_back({i+1, a[i+1]});
		if(b[i+1] == -1){
			s.push({i+1, a[i+1]});
			q.push(i+1);
		}
	}
	
	while(q.size()){
		ll x = q.front();
		q.pop();
		for(auto p: g[x]){
			q.push(p.first);
			s.push(p);
		}
	}
	
	vector<bool> visited(n+1, false);
	ll sum = 0ll;
	vector<ll> ans;
	stack<ll> crap;
	
	while(s.size()){
		ll pos,y;
		tie(pos,y) = s.top();
		//cout << pos << " " << y << "\n";
		if(a[pos]>=0){
			visited[pos] = true;
			if(b[pos]>0) a[b[pos]] += (a[pos]);
			sum += (a[pos]);
			ans.push_back(pos);
		}else{
			crap.push(pos);
		}
		s.pop();
	}
	
	for (int i = 1; i <= n; i++)
	{
		if(!visited[i]){
			sum += (a[i]);
			// ans.push_back(i);
		}
	}
	cout << sum << "\n";
	for(int x: ans){
		cout << x << " ";
	}
	while(crap.size()){
		cout << crap.top() << " ";
		crap.pop();
	}
	cout << "\n";
	return 0;
}
