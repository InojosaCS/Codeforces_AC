#include <bits/stdc++.h>
 
using namespace std;

void solve(){
	int n,x;
	cin >> n >> x;
	int64_t a[n];
	int64_t sum = 0;
	bool free = false;
	
	for (int i = 0; i < n; i++)
	{
		cin  >> a[i];
		sum += a[i];
		if(a[i] == x) free = true;
	}
	
	if(*max_element(a, a+n) == *min_element(a, a+n) && a[0] == x){
		cout << "0\n";
	} else if(x * n == sum || free){
		cout << "1\n";
	} else {
		cout << "2\n";
	}
	
	return;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	int tt = 1;
	cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}
