#include <bits/stdc++.h> 

using namespace std; 

#define int long long

struct pt{
    int x, y;
};

bool valid(pt a, pt b, vector<pt> &v){
    int n = v.size();
    int good = 0;
    vector<pt> line;
    
    for (int i = 0; i < n; i++)
    {
	pt c = v[i];
	int xi = (c.x - a.x);
	int yi = (c.y - a.y);
	int xj = (c.x - b.x);
	int yj = (c.y - b.y);
	
	if(xi * yj == xj * yi){
	    good++;
	} else {
	    line.push_back(c);
	}
    }
    
    int k = line.size();
    
    if(k < 3) return true;
    
    a = line[0];
    b = line[1];

    //cout << good << " first\n";
    
    for (int i = 0; i < k; i++)
    {
	pt c = line[i];
	int xi = (c.x - a.x);
	int yi = (c.y - a.y);
	int xj = (c.x - b.x);
	int yj = (c.y - b.y);
	
	if(xi * yj == xj * yi){
	    good++;
	} else {
	    return false;
	}
    }
    
    //cout << good << " last\n";
    
    return good == n;
}

void solve(int test){
    int n;
    cin >> n;
    
    vector<pt> a(n);
    
    for (int i = 0; i < n; i++)
	cin >> a[i].x >> a[i].y;
    
    bool ans = n < 3 || valid(a[0], a[1], a) || valid(a[0], a[2], a) || valid(a[1], a[2], a);
    
    cout << (ans ? "YES\n" : "NO\n");
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int32_t testCases = 1;
    //cin >> testCases;
    
    while(testCases-->0) solve(testCases + 2);
    
    return 0;
}	
