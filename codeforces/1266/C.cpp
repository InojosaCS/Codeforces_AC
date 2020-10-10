#include <bits/stdc++.h>
 
using namespace std;
 
void solve(){
	int r,c;
	cin >> r >> c;
	int64_t a[r][c], cnt = 2LL;
	
	if(r <= 1 && c <= 1){
		cout << "0\n";
		return;
	}
	
	if(r == 1){
		for (int i = 0; i < c; i++)
			cout << i+2 << (i == c-1 ? "\n" : " ");

		return;
	}
	
	for (int i = 0; i < r; i++)
	{
		a[i][0] = cnt;
		cnt++;
	}
	
	for (int j = 1; j < c; j++)
	{
		for (int i = 0; i < r; i++)
		{
			a[i][j] = a[i][0] * cnt;
		}
		cnt++;
	}
	
	set<int64_t> s;
	
	for (int j = 0; j < c; j++)
	{
		int64_t gcd = 0;
		for (int i = 0; i < r; i++)
		{
			gcd = __gcd(a[i][j], gcd);
		}
		s.insert(gcd);
	}
	
	for (int i = 0; i < r; i++)
	{
		int64_t gcd = 0;
		for (int j = 0; j < c; j++)
		{
			gcd = __gcd(a[i][j], gcd);
		}
		s.insert(gcd);
	}
	
	assert((int) s.size() == r + c && r + c == *max_element(s.begin(), s.end()));
		
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cout << a[i][j] << (j == c-1 ? "\n" : " ");

}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
		
	int t = 1;
	//cin >> t;

	while(t-->0) solve();
	
	return 0;
}
