#include <bits/stdc++.h>
 
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (long long) x.size()
#define watch(x) cout << (#x) << " is " << (x) << endl


int main(){
	ios_base::sync_with_stdio(false);	cin.tie(NULL);

	int n;
	cin >> n;
	if(n%2){
		cout << "black\n";
	}else{
		cout << "white\n1 2\n";
	}
	return 0;
}
