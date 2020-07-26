#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);

	int t;
	cin >> t;
	while(t--){
		long long n,k;
		cin >> n >> k;
		vector<long long> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		
		map<long long, long long> visited;
		
		for (int i = 0; i < n; i++)
		{
			long long now = 0ll, cnt = 1ll;
			while(now < v[i]){
				if(now + cnt == v[i]){
					visited[cnt]++;
					now = now + cnt;
					break;
				}else if(now + cnt > v[i]){
					visited[cnt / k]++;
					now = now + cnt / k;
					cnt = 1ll;
				}else{
					cnt *= k;
				}
			}
			assert(now == v[i]);
		}
		string ans = "YES\n";
		for(auto p : visited){
			if(p.second > 1) ans = "NO\n";
		}
		cout << ans;
	}
	return 0;
}
