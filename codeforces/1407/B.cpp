#include <bits/stdc++.h>
 
using namespace std;

void solve(){
	int n;
	cin >> n;
	std::vector<int64_t> a(n);

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	int64_t current = *max_element(a.begin(), a.end());;
	
	for (int i = 0; i < n; ++i)
	{
		if(a[i] == current){
			a[i] = -1;
			break;
		}
	}

	cout << current << " ";
	for (int i = 1; i < n; ++i)
	{
		int64_t mx = 0;
		for (int j = 0; j < n; ++j)
		{
			if(a[j] == -1) continue;
			mx = max(mx, __gcd(current, a[j]));
		}
		for (int j = 0; j < n; ++j)
		{
			if(a[j] == -1) continue;
			if(__gcd(a[j], current) == mx){
				cout << a[j] << " ";
				current = mx;
				a[j] = -1;
				break;
			}
		}
	}
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 

	int t = 1;
	cin >> t;

	while(t--) solve();
	return 0;
}
