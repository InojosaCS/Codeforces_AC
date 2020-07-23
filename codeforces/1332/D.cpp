#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);
	
	ll k;
	cin >> k;
	ll cnt = 1ll;
	while(cnt<=k)
		cnt *= 2ll;
		
	if(k==0){
		cout << "1 1\n1\n";
	}else{
		cout << "3 4\n";
		vector<vector<ll>> m(3, vector<ll>(4,cnt));
		m[0][1] = m[2][3] = k;
		
		for (int i = 0; i < 3; i++)
			m[i][2] = k;
			
		m[0][0] = m[2][2] = cnt + k;
		
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cout << m[i][j] << " ";
			}
			cout << "\n";
		}
		
		
	}
	return 0;
}
