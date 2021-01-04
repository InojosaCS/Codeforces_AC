#include <bits/stdc++.h> 
 
using namespace std; 

void solve(int test){
    int n;
    cin >> n;
    
    vector<int64_t> a(n);
    
    for (int i = 0; i < n; i++)
    {
	cin >> a[i];
    }
    
    sort(a.rbegin(), a.rend());
    int64_t alice = 0;
    int64_t bob = 0;
    
    for (int i = 0; i < n; i++)
    {
	if(i % 2 == 0 && a[i] % 2 == 0) alice += a[i];
	if(i % 2 && a[i] % 2) bob += a[i];
    }
    
    if(alice == bob){
	cout << "Tie\n";
    } else if(alice > bob){
	cout << "Alice\n";
    } else {
	cout << "Bob\n";
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
