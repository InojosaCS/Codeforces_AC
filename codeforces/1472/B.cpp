#include <bits/stdc++.h> 
 
using namespace std; 

void solve(int test){
    int n;
    cin >> n;
    int cnt = 0, sum = 0;

    for (int i = 0; i < n; i++)
    {
	int x;
	cin >> x;
	if(x == 1) cnt++;
	sum += x;
    }

    if(sum % 2){
	cout << "NO\n";
	return;
    }
    
    if((sum / 2) % 2 && cnt == 0){
	cout << "NO\n";
	return;
    }
    
    cout << "YES\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int32_t testCase = 1;
    cin >> testCase;

    while(testCase-->0) solve(testCase);
    
    return 0;
}	
