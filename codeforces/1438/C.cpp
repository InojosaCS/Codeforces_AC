#include <bits/stdc++.h> 

using namespace std; 

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve(){
    int n,m;
    cin >> n >> m;
    
    vector<vector<int>> a(n+2, vector<int>(m+2, -1));
    vector<vector<int>> v(n+2, vector<int>(m+2, 0));
    map<int,vector<pair<int,int>>> mp;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if((i+j)%2 != a[i][j]%2) a[i][j]++;
        }
    }


    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 0; k < 4; k++) assert(a[i + dx[k]][j + dy[k]] != a[i][j]);
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int32_t tt = 1;
	cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}	
