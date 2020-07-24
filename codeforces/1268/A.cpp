#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define deb(x) cout << (#x) << " is " << (x) << endl;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);

	int n,k;
	cin >> n >> k;
	vector<int> x(n);
	vector<int> rep(n);
	
	for (int i = 0; i < n; i++){
		char c;
		cin >> c;
		x[i] = c-'0';
	}

	for (int i = 0; i < n; i++){
		rep[i] = x[i%k];
	}
	
	bool less = false;
	
	for (int i = 0; i < n; i++){
		if(rep[i] < x[i]){
			less = true;
			break;
		}if(rep[i] > x[i]){
			break;
		}
	}
	
	if(less){
		for (int j = k-1; j > -1; j--)
		{
			if(rep[j]==9){
				rep[j] = 0;
			}else{
				++rep[j];
				break;
			}
		}
	}
	
	less = true;
	
	for (int i = 0; i < k; i++)
	{
		if(x[i] > rep[i] && rep[i]){
			less = false;
		}
	}
	
	for (int i = k; i < n; i++){
		rep[i] = rep[i-k];
	}
	
	assert(less);
	
	cout << n << "\n";
	
	for (int i = 0; i < n; i++)
		cout << rep[i];
		
	cout << "\n";

	
	return 0;
}
