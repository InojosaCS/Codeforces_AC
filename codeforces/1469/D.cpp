#include <bits/stdc++.h> 
 
using namespace std; 

void solve(int test){
    int n;
    cin >> n;
    //n = test + 3;
    
    vector<pair<int,int>> ans;
    int cnt = 0;
    int x = n;
    
    int pp = 1, cp = 0;
    while(pp <= 32 && pp < n) pp *= 2, cp++;
    pp /= 2;
    cp--;
    
    for (int i = 3; i < n; i++)
	if(i != pp)
	    ans.push_back({i, i+1}), cnt++;
    
    while(x != 1){
	x = (x+pp-1) / pp;
	ans.push_back({n, pp});
	cnt++;
    }
    
    for (int i = 0; i < cp && pp != 2; i++)
	ans.push_back({pp, 2}), cnt++;    

    assert(n + 5 >= cnt);
    cout << cnt << "\n";
    
    for(auto p: ans){
	cout << p.first << " " << p.second << "\n";
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
