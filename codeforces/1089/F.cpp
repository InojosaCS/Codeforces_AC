#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void shift_solution(int & x, int & y, int a, int b, int cnt) {
    x += cnt * b;
    y -= cnt * a;
}


void solve(){
	for(int tc = 0; tc < 1; tc++){
		int64_t n, old;
		cin >> n;
		//n = tc;
		old = n;
		vector<int64_t> divs;
		
		for (int i = 2; i*i <= n; i++)
		{
			if(n % i  == 0) divs.push_back(i);
			while(n % i  == 0) n /= i;
		}
		
		if(n > 1) divs.push_back(n);
		
		
		if((int) divs.size() <= 1){
			cout << "NO\n";
			continue;
		}
		
		n = old;
		int64_t a = divs[0], b = divs[1], c = divs[0]*divs[1];
		int x, y, minx = 0, miny = 0, g;
		find_any_solution(a, b, c-1, x, y, g);
		
		
		int sign_a = a > 0 ? +1 : -1;
		int sign_b = b > 0 ? +1 : -1;
	
		shift_solution(x, y, a, b, (minx - x) / b);
		if (x < minx)
			shift_solution(x, y, a, b, sign_b);
	
		shift_solution(x, y, a, b, -(miny - y) / a);
		if (y < miny)
			shift_solution(x, y, a, b, -sign_a);
		
		vector<pair<int,int>> ans;
		
		while(x > 0){
            int num = min(b * (n/c) - 1, x);
            int d = b * (n/c);
        	ans.push_back({num, d});
            x -= num;
        }
        
		while(y > 0){
            int num = min(a * (n/c) - 1, y);
            int d = a * (n/c);
        	ans.push_back({num, d});
            y -= num;
        }
        
		int h = __gcd(n, n-c);
		if(n > c) ans.push_back({(n-c) / h, n / h});
		
		int64_t sum = 0;
		int64_t den = 1;
		
		for(auto p: ans){
			sum += (n/p.second) * p.first;
			den = den * p.second / __gcd(p.second, den);
		}
	
		assert(a != b);
		assert(x >= 0);
		assert(y >= 0);
		assert(sum == n-1);
		assert(den == n);
	
		cout << "YES\n";
		cout << (int) ans.size() << "\n";
		
		for(auto p: ans){
			cout << p.first << " " << p.second << "\n";
			//sum += (n/p.second) * p.first;
			//den = den * p.second / __gcd(p.second, den);
		}

	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int32_t tt = 1;
	//cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}	
