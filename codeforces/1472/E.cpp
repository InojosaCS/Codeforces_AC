#include <bits/stdc++.h>
 
using namespace std;

bool deb = false;

void solve(int test){
    int n;
    cin >> n;
    
    vector<tuple<int,int,int>> bx(n);
    vector<tuple<int,int,int>> bx2(n);
    set<tuple<int,int,int>> by;
    set<tuple<int,int,int>> by2;

    
    for (int i = 0; i < n; i++)
    {
	int x, y;
	cin >> x >> y;
	if(x > y) swap(x, y);
	bx[i] = {-x, y, i};
	bx2[i] = {-y, x, i};
	by.insert({-y, x, i});
	by2.insert({-y, x, i});
    }
    
    
    sort(bx.begin(), bx.end());
    sort(bx2.begin(), bx2.end());

    vector<int> ans(n, -1);
    
    for (int k = 0; k < n; k++)
    {
	int x, y, i;
	tie(x,y,i) = bx[k];
	x = -x;
	
	if(deb) cout << x << " " <<  y << " ***\n";
	
	if(by.lower_bound({-y+1, 0, -1}) == by.end()){
	    by.erase({-y,x,i});
	    continue;
	}
	
	int a,b,c;
	tie(a,b,c) = *by.lower_bound({-y+1, 0, -1});
	
	if(deb) cout << b << " " <<  a <<  " " << i << " ---\n";
	
	ans[i] = c + 1;
	by.erase({-y,x,i});
    }

    //by = by2;
    //bx = bx2;
    
    //for (int k = 0; k < n; k++)
    //{
	//int x, y, i;
	//tie(x,y,i) = bx[k];
	//x = -x;
	
	//cout << x << " " <<  y << " ***\n";
	
	//if(by.lower_bound({-y+1, 0, -1}) == by.end()){
	    //by.erase({-y,x,i});
	    //continue;
	//}
	
	//int a,b,c;
	//tie(a,b,c) = *by.lower_bound({-y+1, 0, -1});
	
	//cout << b << " " <<  a <<  " " << i << " ---\n";
	
	//ans[i] = c + 1;
	//by.erase({-y,x,i});
    //}
    
    if(deb) cout << "TEST: ---------------------\n";
    
    for (int i = 0; i < n; i++)
    {
	cout << ans[i] << " \n"[i==n-1];
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int32_t testCase = 1;
    cin >> testCase;

    while(testCase-->0) solve(testCase);
    
    return 0;
}	
