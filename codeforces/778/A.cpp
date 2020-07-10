#include <bits/stdc++.h>
 
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (long long) x.size()
#define debug(x) cout << (#x) << " is " << x << "\n"

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.precision(20);
	
	string t,p;
	cin >> t >> p;
	int n = sz(t), m = sz(p);
	vector<int> a(n);
	t = "#" + t;

	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	int l = 0, r = n - m, cool = 0;

	while(l<=r){
		int mid = (l+r)/2;
		vector<pair<int, char>> aux;
		for (int i = mid; i < n; ++i)
			aux.push_back({a[i], t[a[i]]});
		
		sort(all(aux));

		int cnt = 0;
		for(auto c: aux){
			if(cnt<m && c.second==p[cnt])
				cnt++;
		}
		if(cnt==m){
			l = mid + 1;
			cool = mid;
			// for(auto c: aux)
			// 	cout << c << " ";
			// cout << "\n";
		}else{
			r = mid - 1;
		}
	}
	cout << cool << "\n";
	return 0;
}
