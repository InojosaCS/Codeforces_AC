#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define debug(x) cout << (#x) << " is " << (x) << endl

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);
	
	long long n;
	cin >> n;
	long long adj[n+1][n+1], dist[n+1][n+1], arr[n+1];

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> adj[i][j];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dist[i][j] = 0;
			dist[i][j] = 1e18;
		}
	}

	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	
	reverse(arr, arr+n+1);
	vector<bool> visited(n,0);
	std::vector<long long> ans;

	for (int k = 1; k <= n; k++) {
		visited[arr[k]] = 1;
		long long sum = 0ll;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if(adj[i][arr[k]] + adj[arr[k]][j] < adj[i][j])
					adj[i][j] = adj[i][arr[k]] + adj[arr[k]][j];
				if(visited[i] && visited[j])
					sum += adj[i][j];
			}
		}

		//cout << sum << "\n";
		ans.push_back(sum);
	}

	reverse(all(ans));
	for (int i = 0; i < sz(ans); ++i)
	{
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}