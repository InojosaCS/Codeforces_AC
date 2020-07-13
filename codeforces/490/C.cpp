#include <bits/stdc++.h>
 
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define debug(x) cout << (#x) << " is " << (x) << endl

long long expo(long long a, long long b){
	if(b==0ll) return 1ll;
	if(b==1) return a;
	else return expo(a*a,b/2)*(b%2 ? a : 1ll);
}

long long szk(long long k){
	long long cnt = 0ll;
	while(k){
		cnt++;
		k/=10ll;
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);	cin.tie(NULL);

	string s, t;
	cin >> s;
	long long a,b,expA=1ll,expB=1ll;
	cin >> a >> b;
	std::vector<long long> prefixA(sz(s)+3,0), prefixB(sz(s)+1,0);
	reverse(all(s));
	s = "#" + s;

	for (int i = 1; i < sz(s); ++i)
	{
		prefixB[i] = (prefixB[i-1] + ((s[i]-'0')*expB)%b)%b;
		expB = (expB*10ll)%b;
	}
	for (int i = sz(s)-1; i > 0; --i)
	{
		prefixA[i] = (prefixA[i+1]*10ll + (s[i]-'0'))%a;
		//debug(prefixA[i]);
	}

	for (int i = 1; i < sz(s)-1; ++i)
	{
		if(s[i]!='0' && prefixB[i]==0 && prefixA[i+1]==0){
			cout << "YES\n";
			for (int j = sz(s)-1; j > i; --j)
				cout << s[j];
			cout << "\n";
			for (int j = i; j > 0; --j)
				cout << s[j];
			cout << "\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}
