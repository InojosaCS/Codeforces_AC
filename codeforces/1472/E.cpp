#include <bits/stdc++.h>
 
using namespace std;

void solve(int test){
    // input
    int n;
    cin >> n;
    
    // In bx I sort by greater X coordinate, and then by smaller Y coordinate
    vector<tuple<int,int,int>> bx(n);
    
    // In by I sort by greater Y coordinate, and then by smaller X coordinate
    set<tuple<int,int,int>> by;

    // input
    for (int i = 0; i < n; i++)
    {
	int x, y;
	cin >> x >> y;
	if(x > y) swap(x, y);
	bx[i] = {-x, y, i};
	by.insert({-y, x, i});
    }
    
    // Now we sort as described
    sort(bx.begin(), bx.end());

    // where I keep the answer
    vector<int> ans(n, -1);
    
    // Now I go from the upper right corner to the bottom left corner
    // looking for something under Xk, Yk, since I have deleted all 
    // points to the right I must only look for those under Yk, thats why 
    // Im using lower bound
    for (int k = 0; k < n; k++)
    {
	int x, y, i;
	tie(x,y,i) = bx[k];
	x = -x;
	
	// Checking if something exists
	if(by.lower_bound({-y+1, 0, -1}) == by.end()){
	    by.erase({-y,x,i});
	    continue;
	}
	
	// Saving the answer
	int a,b,c;
	tie(a,b,c) = *by.lower_bound({-y+1, 0, -1});
	ans[i] = c + 1;
	// erasing the current point to avoid false positive
	by.erase({-y,x,i});
    }
    
    // output
    for (int i = 0; i < n; i++)
	cout << ans[i] << " \n"[i==n-1];

    return;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int32_t testCase = 1;
    cin >> testCase;

    while(testCase-->0) solve(testCase);
    
    return 0;
}	
