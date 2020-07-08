#include <bits/stdc++.h>
 
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (long long) x.size()

int main(){
	
	long long u,v;
	cin >> u >> v;

	if (u>v || u%2!=v%2)
	{
		cout << "-1\n";
	}
	else
	{
		vector<long long> arr(1000,0ll);
		vector<long long> arr2(1000,0ll);
		bitset<62> binary(u);

		for (long long i = 0; i < 62; ++i)
			if((1ll << i) & u)
				arr.push_back(1ll << i);
		
		arr2.push_back(u);
		long long diff = v - u;
		bitset<62> binaryDiff(diff);
		sort(all(arr), greater<long long>());
		sort(all(arr2), greater<long long>());

		for (int i = 0; i < 62; ++i)
		{
			if(binaryDiff[i])
			{
				int cnt = 0;
				for (int x = 0; x < sz(arr) && cnt<2; ++x)
				{
					if(!(arr[x] & (1ll << (i-1)))){
						arr[x] += (1ll << (i-1));
						cnt++;
					}
				}
				cnt = 0;
				for (int x = 0; x < sz(arr2) && cnt<2; ++x)
				{
					if(!(arr2[x] & (1ll << (i-1)))){
						arr2[x] += (1ll << (i-1));
						cnt++;
					}
				}
			}
		}
		sort(all(arr), greater<long long>());
		sort(all(arr2), greater<long long>());
		int n = 0, m = 0;
		for (int i = 0; i < sz(arr) && arr[i]!=0; ++i)
			n++;
		
		for (int i = 0; i < sz(arr2) && arr2[i]!=0; ++i)
			m++;

		cout << min(n,m) << "\n";

		if(n<m){
			for (int i = 0; i < sz(arr) && arr[i]!=0; ++i)
				cout << arr[i] << " ";
		
			cout << "\n";
		}
		else{
			for (int i = 0; i < sz(arr2) && arr2[i]!=0; ++i)
				cout << arr2[i] << " ";
		
			cout << "\n";
		}
	}
	return 0;
}
