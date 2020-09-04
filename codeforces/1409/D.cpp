#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define deb(x) cout << (#x) << " is " << (x) << "\n";
#define debv(v) for (auto usb: v) cout << usb << " "; cout << "\n";

// n == (1 \/ 0) ????, memory?

void solve(){
	ll n,s,old;
	cin >> n >> s;
	
	old = n;
	ll sum = 0, t = 0;
	vector<int> ans(20, 0), copy(20,0);
	
	
	while(old){
		ans[t] = copy[t] = old % 10;
		sum += (old % 10);
		old /= 10;
		t++;
	}
	
	if(sum <= s){
		cout << "0\n";
		return;
	}
	
	old = n;
	sum = s - sum;
	int i = 0;
	
	while(sum <= 0){
		sum += (old % 10);
		old /= 10;
		ans[i] = 0;
		i++;
	}
	
	int one = 1;
	for (int k = i; k < 19; k++)
	{
		int temp = (one + ans[k]) / 10;
		ans[k] = (one + ans[k]) % 10;
		one = temp;
	}
	
	one = 0;
	vector<int> lazy(19, 0);

	for (int k = 0; k < 19; k++)
	{
		lazy[k] = (10 + ans[k] - copy[k]) % 10;
		one = (ans[k] - copy[k] < 0) ? -1 : 0;
		ans[k+1] += one;
	}
	
	ll result = 0;
	ll ppow = 1;
	
	for (int k = 0; k < 18; k++)
	{
		result += ppow * lazy[k];
		ppow *= 10;
	}
	
	cout << result << "\n";
	
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(20);	

	int t = 1;
	cin >> t;

	while(t--) solve();
	//cout << "OK\n";
	
	return 0;
}
