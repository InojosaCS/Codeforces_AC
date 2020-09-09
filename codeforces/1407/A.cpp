#include <bits/stdc++.h>
 
using namespace std;

void solve(){
	int n;
	cin >> n;
	long long a = 0;
	long long x;

	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		a += x;
	}

	if(a > n/2){
		cout << n/2 + (n/2)%2 << "\n";
		for (int i = 0; i < n/2 + (n/2)%2; ++i)
		{
			cout << "1 ";
		}
	} else {
		cout << n/2 << "\n";
		for (int i = 0; i < n/2; ++i)
		{
			cout << "0 ";
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
