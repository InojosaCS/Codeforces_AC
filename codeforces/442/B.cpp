#include <bits/stdc++.h> 

using namespace std; 

long double get(vector<long double> &v){
	long double ans = 0;
	int n = v.size();
	for (int i = 0; i < n; i++)
	{
		long double curr = v[i];
		for (int j = 0; j < n; j++)
		{
			if(i == j) continue;
			curr *= (1.0 - v[j]);
		}
		ans += curr;
	}
	return ans;
}

long double allCombinations(vector<long double> &v){
	
	int n = v.size();
	long double ans = 0.0;
	
	for (int mask = 0; mask < (1 << n); mask++)
	{
		vector<long double> temp;
		for (int i = 0; i < n; i++)
		{
			if(mask & (1 << i)) temp.push_back(v[i]);
		}
		ans = max(ans, get(temp));
	}
	return ans;
}

void solve(){
	int n;
	cin >> n;
	
	vector<long double> a(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	sort(a.rbegin(), a.rend());
	long double ans = *max_element(a.begin(), a.end());
	//long double ans2 = allCombinations(a);
	
	for (int i = 0; i < n; i++)
	{
		vector<long double> temp;
		for (int j = 0; j <= i; j++)
			temp.push_back(a[j]);
		ans = max(ans, get(temp));
	}
	
	//assert(ans == ans2);
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << std::setprecision(22);
	
	int32_t tt = 1;
	//cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}	
