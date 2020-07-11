#include <bits/stdc++.h>
 
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (long long) x.size()
#define debug(x) cout << (#x) << " is " << x << "\n"

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.precision(20);
	
	int t;
	cin >> t;

	while(t--){
		int n,x;
		cin >> n >> x;
		string s;
		vector<int> ones(n+1,0), zeroes(n+1,0), pre(n+1,0);
		cin >> s;
		s = "#" + s;
		for (int i = 1; i < sz(s); ++i)
		{
			ones[i] = ones[i-1] + (s[i] == '1');
			zeroes[i] = zeroes[i-1] + (s[i] == '0');
			pre[i] = zeroes[i] - ones[i];
		}

		if(pre[n]==0){
			string ans = "0\n";
			for (int i = 1; i < n+1; ++i)
				if(pre[i]==x)
					ans = "-1\n";
			cout << ans;
		}else{
			int ans = x==0;
			for (int i = 1; i < n+1; ++i)
				if((x-pre[i])%pre[n]==0 && (x-pre[i])/pre[n]>=0)
					ans++;
			
			cout << ans << "\n";
		}
	}
	return 0;
}
