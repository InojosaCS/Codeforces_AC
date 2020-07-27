#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;

ll maxEvenLenSum(vector<long long> arr, int n) 
{ 
  
    if (n < 2ll) 
        return 0ll; 
  
    ll dp[n] = { 0ll }; 
  
    dp[n - 1] = 0ll; 
    dp[n - 2] = arr[n - 2] + arr[n - 1]; 
  
    for (int i = n - 3; i >= 0; i--) { 
  
        dp[i] = arr[i] + arr[i + 1]; 
  
        if (dp[i + 2] > 0ll) 
            dp[i] += dp[i + 2]; 
    } 
 
    ll maxSum = *max_element(dp, dp + n); 
    return maxSum; 
} 

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<long long> a(n), b(n);
		ll sum = 0ll;
		
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			b[i] = i%2 ? a[i] : -a[i];
			if(i%2 == 0) sum += a[i];
		}
		
		ll k = maxEvenLenSum(b,n);
		if(k>0ll) cout << sum + k << "\n";
		else cout << sum << "\n";
		
	}

	return 0;
}
