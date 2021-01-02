#include <bits/stdc++.h> 
 
using namespace std; 

void solve(int test){
    int r, c;
    cin >> r >> c;
    
    int64_t sum = 0, mn = 1e18, cnt = 0;
    bool zero = false;
    
    for (int i = 0; i < r; i++)
    {
	for (int j = 0; j < c; j++)
	{
	    int64_t x;
	    cin >> x;
	    sum += abs(x);
	    if(x < 0) cnt++;
	    if(x == 0) zero = true;
	    mn = min(abs(x), mn);
	}
    }
    
    if(!zero && cnt % 2) sum -= 2LL*mn;
    
    cout << sum << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int32_t testCase = 1;
    cin >> testCase;

    while(testCase-->0) solve(testCase);
    
    return 0;
}	
