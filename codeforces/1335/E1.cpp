#include <bits/stdc++.h>
 
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (long long) x.size()

int solve(){
	int n;
	cin >> n;
	vector<int> a(n+3), numbers, rep(27,0);
	vector<vector<int>> prefix(27, vector<int>(n+3,0));
	set<int> s;

	for (int i = 1; i <= n; ++i)
	{	
		cin >> a[i];
		rep[a[i]]++;
		if(s.count(a[i])==0)
			numbers.push_back(a[i]);
		s.insert(a[i]);
	}
	
	for (int i = 1; i < 27; ++i)
		for (int j = 1; j <= n; ++j)	
			prefix[i][j]= prefix[i][j-1] + (a[j]==i);
		
	vector<pair<int,int>> combination;

	for(int i=0; i< sz(numbers); i++)
		for (int j = i+1; j < sz(numbers); ++j)
		{
			combination.push_back({numbers[i], numbers[j]});
			combination.push_back({numbers[j], numbers[i]});
		}

	vector<int> allCombinations;
	allCombinations.push_back(0);

	for(auto par: combination){
		int x = par.first;
		int y = par.second;
		int first = 1, last = n, l = 0, r = 0;
		int cmx = 0;
		//cout << x << " " << y << "\n";
		for (int i = 1; i <= rep[x]/2; ++i)
		{
			while(l<i){
				if(a[first]==x){
					l++;
				}
				first++;
			}
			while(r<i){
				if(a[last]==x){
					r++;
				}
				last--;
			}
			int current = (i*2 + prefix[y][last] - prefix[y][first-1]);
			cmx = max(cmx, current);
		}
		allCombinations.push_back(cmx);
	}

	int ans = max(*max_element(all(allCombinations)), *max_element(all(rep)));
	//ans = *max_element(all(rep));
	return ans;
}

int main(){
	
	int tt;
	cin >> tt;
	while(tt--){
		cout << solve() << "\n";
	}
	return 0;
}
