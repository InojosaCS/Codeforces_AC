#include <bits/stdc++.h>
 
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (long long) x.size()
#define debug(x) cout << (#x) << " is " << x << "\n"

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.precision(20);
	
	long long n,k;
	cin >> n >> k;
	vector<long long> a(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	map<long long, long long> primero;
	map<long long, long long> segundo;
	map<long long, long long> tercero;

	for (int i = 0; i < n; ++i)
	{
		if(a[i]%(k*k)==0){
			tercero[a[i]] += segundo[a[i]/k];
		}
		if(a[i]%k==0){
			segundo[a[i]] += primero[a[i]/k];
		}
		primero[a[i]]++;
	}
	
	long long ans = 0ll;
	for(auto x: tercero){
		ans += x.second;
	}
	cout << ans << "\n";
	return 0;
}
