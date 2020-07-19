#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define debug(x) cout << (#x) << " is " << (x) << endl

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		bitset<110> impar, par;
		for (int i = 0; i < n; ++i)
		{
			int a;
			cin >> a;
			if (a%2)
				impar[i] = 1;
			else
				par[i] = 1;
		}
		if(par.count()){
			cout << "1\n";
			for (int i = 0; i < n; ++i){
				if(par[i]){
					cout << i+1 << "\n";
					break;
				}
			}
		}else if(impar.count()>=2){
			cout << "2\n";
			int cnt = 0;
			for (int i = 0; i < n && cnt<2; ++i)
			{
				if(impar[i]){
					cnt++;
					cout << i+1 << " ";
				}
			}
			cout << "\n";
		}else{
			cout << "-1\n";
		}
	}
	return 0;
}