#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;
#define debv(v) for (auto x: v) cout << x << " "; cout << "\n";

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);	
	
	int n;
	cin >> n;
	vector<int> a(n);
	set<int> ans;
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	sort(all(a));
	
	if(n == 1){
		cout << "-1\n";
	}else if(n == 2){
		ans.insert(a[0] - (a[1] - a[0]));
		ans.insert(a[1] + (a[1] - a[0]));
		if((a[1] - a[0])%2 == 0){
			ans.insert(a[0] + (a[1] - a[0]) / 2);
		}
		cout << ans.size() << "\n";
		debv(ans);
	}else{
		map<int,int> cnt;
		set<int> s;
		for (int i = 1; i < n; i++)
		{
			cnt[a[i]-a[i-1]]++;
			s.insert(a[i]-a[i-1]);
		}
		if(sz(s) > 2){
			cout << sz(ans) << "\n";
		}else if(sz(s) == 1){
			ans.insert(a[0] - *s.begin());
			ans.insert(a[n-1] + *s.begin());

			cout << sz(ans) << "\n";
			debv(ans);
		}else{
			int l = *s.begin();
			auto it = s.end();
			it--;
			int r = *it;
			if(l*2 == r && cnt[r] == 1){
				int k;
				for (int i = 1; i < n; i++)
				{
					if(a[i]-a[i-1] == r) k = a[i-1] + l;
				}
				cout << "1\n" << k << "\n";
			}else{
				cout << "0\n";
			}
			
		}
		
	}
	return 0;
}
