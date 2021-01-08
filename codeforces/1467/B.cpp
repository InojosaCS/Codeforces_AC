#include <bits/stdc++.h> 

using namespace std; 

bool peak(int i, int j, int k){
    return (j < i && j < k) || (j > i && j > k);
}

void solve(int test){
    int n;
    cin >> n;
    
    vector<int> a(n + 2);
    vector<int> h(n + 2, 0);
    vector<int> v(n + 2, 0);
    int cnt = 0;
    
    for (int i = 1; i <= n; i++)
    {
	cin >> a[i];	
    }
    
    a[0] = a[1];
    a[n+1] = a[n];
    
    if(n <= 3){
	cout << "0\n";
	return;
    }
    
    for (int i = 1; i <= n; i++)
    {
	if(a[i] > a[i-1] && a[i] > a[i+1]) h[i] = 1,cnt++;
	if(a[i] < a[i-1] && a[i] < a[i+1]) v[i] = 1, cnt++;
    }

    int ans = cnt;
    
    for (int i = 2; i + 1 <= n; i++)
    {
	int copy = a[i];
	a[i] = a[i-1];
	int old = (h[i] || v[i]) + (h[i-1] || v[i-1]) + (h[i+1] || v[i+1]); 
	int x = peak(a[i-2], a[i-1], a[i]);
	int y = peak(a[i-1], a[i], a[i+1]);
	int z = peak(a[i], a[i+1], a[i+2]);
	int diff = old - (x + y + z);
	ans = min(cnt - diff, ans);
	a[i] = copy;
    }
    
    for (int i = 2; i + 1 <= n; i++)
    {
	int copy = a[i];
	a[i] = a[i+1];
	int old = (h[i] || v[i]) + (h[i-1] || v[i-1]) + (h[i+1] || v[i+1]); 
	int x = peak(a[i-2], a[i-1], a[i]);
	int y = peak(a[i-1], a[i], a[i+1]);
	int z = peak(a[i], a[i+1], a[i+2]);
	int diff = old - (x + y + z);
	ans = min(cnt - diff, ans);
	a[i] = copy;
    }
    
    cout << max(ans, 0) << "\n";
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int32_t testCases = 1;
    cin >> testCases;
    
    while(testCases-->0) solve(testCases);
    
    return 0;
}	
