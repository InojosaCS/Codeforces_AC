#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    
    vector<int> a(n);
    
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<pair<int,int>> one;
    vector<pair<int,int>> both;
    vector<pair<int,int>> ans;
    vector<int> visited(2*n, 0);
    int nextZero = n;
    //int nextOne = n, nextTwo = n, index = n;
    
    for (int i = n-1; i > -1; i--)
    {
		if(a[i] == 0) continue;
        if(a[i] == 1){
            one.push_back({nextZero, i+1});
            ans.push_back({nextZero, i+1});
            visited[nextZero]++;
            //nextZero--;
        }
        
        if(a[i] == 2){
            if(one.size()){
                pair<int,int> k = one.back();
				one.pop_back();
                ans.push_back({k.first, i+1});
                both.push_back({k.first, i+1});
                visited[k.second]++;
            } else {
                cout << "-1\n";
                return;
            }
        }
        
        if(a[i] == 3){
            if(both.size()){
                pair<int,int> k = both.back();
                both.pop_back();
				ans.push_back({nextZero, k.second});
                ans.push_back({nextZero, i+1});
                both.push_back({nextZero, i+1});
                visited[nextZero]++;
            }
            else if(one.size()){
                pair<int,int> k = one.back();
				one.pop_back();
				ans.push_back({nextZero, k.second});
                ans.push_back({nextZero, i+1});
                both.push_back({nextZero, i+1});
                visited[nextZero]++;
            } else {
				cout << "-1\n";
				return;
			}
        }
        while(visited[nextZero] > 0) nextZero--;
    }
    
    sort(ans.begin(), ans.end());
    
    cout << ans.size() << "\n";
    
	//vector<vector<int>> check(n, vector<int>(n, 0));
	
    for(auto x: ans) {
        cout << x.first << " " << x.second << "\n";
        //check[x.first-1][x.second-1] = 1;
    }
    
    //for (int i = 0; i < n; i++)
		//for (int j = 0; j < n; j++)
			//cout << check[i][j] << (j == n-1 ? "\n" : " ");
	
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	int tt = 1;
	//cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}
