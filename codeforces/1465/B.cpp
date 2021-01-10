#include <bits/stdc++.h> 

using namespace std; 

bool valid(int64_t n){
    int64_t v = n;
    set<int64_t> a;
    
    while(v){
	a.insert(v % 10);
	v /= 10;
    }
    
    for(int64_t x: a){
	if(x && n % x){
	    return false;
	}
    }
    
    return true;
}

void solve(int test){
    int64_t n;
    cin >> n;
    
    while(!valid(n)) n++;
    
    cout << n << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int32_t testCases = 1;
    cin >> testCases;
    
    while(testCases-->0) solve(testCases + 2);
    
    return 0;
}	
