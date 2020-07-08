#include <bits/stdc++.h>
 
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (long long) x.size()

int main(){
	
	int p,n;
	cin >> n >> p;
	p--;
	string s, copy;
	cin >> s;
    copy = s;
    reverse(all(copy));

	if(s == copy){
		cout << "0\n";
	}else{

		int first = 1e7, last = -1;
		int l = (p*2>=n) ? n/2 + (n%2) : 0;
		int r = (p*2>=n) ? n-1 : n/2 - 1;		

		for(int i=l; i<=r; i++){
			if(s[i]!=copy[i]){
				first = min(first, i);
				last = max(last, i);
			}
		}

		int ans = max(0, p-first) + max(0, last-p);

		if (first<=p && p<=last)
		{
			ans += min(p-first, last-p);
		}

		//cout << first << " " << last << " " << ans << "\n";
		for (int i = 0; i < n/2; ++i)
		{
			int y = max(s[i]-'a', copy[i]-'a');
			int x = min(s[i]-'a', copy[i]-'a');
			ans += min(y-x, (26-y)+x);
		}
		cout << ans << "\n";
	}
	return 0;
}
