#include <bits/stdc++.h> 

using namespace std; 

void solve(){
	string str;
	cin >> str;
	int K;
	cin >> K;
	vector<char> s(str.begin(), str.end());
	
	for (int i = 0; i < K; i++)
		s.push_back('*');
	
	int n = s.size();
	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; i + 2*j - 1 < n; j++)
		{
			bool works = true;
			for (int k = 0; k < j; k++)
			{
				if(s[i + k] == s[i + k + j] || s[i + k + j] == '*' || s[i + k] == '*')
					continue;
				works = false;
				break;
			}
			if(works) ans = max(ans, j);
		}
	}
		
	cout << 2*ans << "\n";
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
