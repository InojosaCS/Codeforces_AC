#include <bits/stdc++.h>
 
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (long long) x.size()

int solve(){
	int n;
	cin >> n;
	vector<int> a(n+3), numbers, rep(207,0);
	vector<vector<int>> prefix(207, vector<int>(n+3,0)), left(207), right(207);
	set<int> s;

	for (int i = 1; i <= n; ++i)
	{	
		cin >> a[i];
		left[a[i]].push_back(i);
		rep[a[i]]++;		
		if(s.count(a[i])==0)
			numbers.push_back(a[i]);
		s.insert(a[i]);
	}
	
	for(int i=n; i>0; i--){
		right[a[i]].push_back(i);
	}
	for (int i = 1; i < 207; ++i)
		for (int j = 1; j <= n; ++j)	
			prefix[i][j]= prefix[i][j-1] + (a[j]==i);
		
	vector<pair<int,int>> combination;
	int cmx = *max_element(all(rep));

	for(int i=0; i< sz(numbers); i++)
		for (int j = i+1; j < sz(numbers); ++j)
		{
			if(rep[numbers[i]]+rep[numbers[j]]<=cmx){
				continue;
			}
			combination.push_back({numbers[i], numbers[j]});
			combination.push_back({numbers[j], numbers[i]});
		}
	
	for(auto par: combination){
		int x = par.first;
		int y = par.second;
		int first = 1, last = n;
		if(rep[x]+rep[y]<=cmx){
			continue;
		}
		//cout << x << " " << y << "\n";
		for (int i = 1; i <= rep[x]/2; ++i)
		{
			first = left[x][i-1];
			last = right[x][i-1];
			int current = (i*2 + prefix[y][last-1] - prefix[y][first]);
			cmx = max(cmx, current);
		}
	}

	return cmx;
}

int main(){
	
	int tt;
	cin >> tt;
	while(tt--){
		cout << solve() << "\n";
	}
	return 0;
}
