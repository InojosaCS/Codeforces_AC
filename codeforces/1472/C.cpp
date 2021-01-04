#include <bits/stdc++.h> 
 
using namespace std; 

void solve(int test){
    int n;
    cin >> n;
    
    vector<int64_t> a(n);
    vector<int64_t> score(n, 0);
    
    for (int i = 0; i < n; i++)
    {
	cin >> a[i];
    }
    
    for (int i = n-1; i > -1; i--)
    {
	int next = a[i] + i;
	if(next > n-1) score[i] = a[i];
	else score[i] = a[i] + score[next];
    }
    
    //for (int i = 0; i < n; i++)
    //{
	//cout << score[i] << " \n"[i==n-1];
    //}
    
    cout << *max_element(score.begin(), score.end()) << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int32_t testCase = 1;
    cin >> testCase;

    while(testCase-->0) solve(testCase);
    
    return 0;
}	
