#include <bits/stdc++.h>
 
using namespace std;

void solve(){
	int64_t n;
	cin >> n;
	int64_t a[n], sum = 0LL;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	
	if(sum % n != 0){
		cout << "-1\n";
		return;
	}
	
	int64_t goal = sum / n;
	vector < tuple <int64_t, int64_t, int64_t> > ans;
	
	for (int i = 1; i < n; i++)
	{
		// pushing from a[0] to a[x] up to closest k*(x+1)
		int64_t diff = ((i+1) - (a[i] % (i+1))) % (i+1);
		ans.push_back({1, 1+i, diff}); 
		a[i] += diff;
		a[0] -= diff;
		
		// pushing from a[x] to a[0]
		ans.push_back({i+1, 1, a[i] / (i+1)}); 
		a[0] += a[i];
		a[i] -= a[i];
	}
	
	for (int i = 1; i < n; i++)
	{
		ans.push_back({1, i+1, goal});
		a[0] -= goal;
		a[i] += goal;
	}
	
	assert(*max_element(a, a+n) == *min_element(a, a+n));
	
	cout << ans.size() << "\n";
	
	for(auto t: ans){
		int64_t a1, b1, c1;
		tie(a1, b1, c1) = t;
		cout << a1 << " " << b1 << " " << c1 << "\n";
	}
	
	return;
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	cout.precision(20);
		
	long double tt = 1;
	cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}
