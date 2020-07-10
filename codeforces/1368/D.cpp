#include <bits/stdc++.h>
 
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (long long) x.size()
#define debug(x) cout << (#x) << " is " << x << "\n"

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.precision(20);
	
	int n, N = 22;
	cin >> n;
	vector<long long> a(n), cnt(N,0);

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort(all(a), greater<long long>());

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if(a[i] & (1ll << j)){
				cnt[j]++;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if((a[i] & (1ll << j))==0 && cnt[j]){
				cnt[j]--;
				a[i] += (1ll << j);
			}else if((a[i] & (1ll << j)) && cnt[j]==0){
				a[i] -= (1ll << j);
			}else if((a[i] & (1ll << j)) && cnt[j]>0){
				cnt[j]--;
			}
		}
	}


	long long sum = 0ll;

	for (int i = 0; i < n; ++i)
		sum += a[i]*a[i];

	cout << sum << "\n";
	return 0;
}
