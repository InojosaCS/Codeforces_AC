#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define debug(x) cout << (#x) << " is " << (x) << endl
#define ll long long


std::vector<int> a(1e5,0), b(1e5,0);
vector<pair<long long, long long>> tree(1e6, {0,0});
long long sz = 1;

void update(int a, int b, int diff, int cnt) {
	a += sz/2 -1; b += sz/2 - 1;
	
	// for (int i = 0; i < sz+1; ++i)
	// {
	// 	if(!(i&(i-1))){
	// 		cout << "\n";
	// 	}
	// 	cout << tree[i].first << " ";
	// }
	// cout << "\n";
	
	while (a <= b) {
	if (a%2 == 1) tree[a++] = {diff, cnt};
	if (b%2 == 0) tree[b--] = {diff, cnt};
	a /= 2; b /= 2;
	}
	// for (int i = 0; i < sz+1; ++i)
	// {
	// 	if(!(i&(i-1))){
	// 		cout << "\n";
	// 	}
	// 	cout << tree[i].first << " ";
	// }
	// cout << "\n";
}

int get(int pos){
	int k = pos + sz/2 -1;
	int posest = -1;
	int val = b[pos-1];
	int best = 0;
	while(k){
		// cout << k << " " << tree[k].second << "  "
		// 	<< tree[k].first <<  " " << posest << "********\n";
		if(tree[k].second>best){
			val = a[pos+tree[k].first-1	];
			best = tree[k].second;
		}
		k/=2;
	}
	return val;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);
	
	int n,m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	
	while(sz<n)
		sz *= 2;
	
	sz *= 2;
	// debug(sz);

	for (int i = 0; i < m; ++i)
	{
		int t;
		cin >> t;
		if(t==1){
			int x,y,k;
			cin >> x >> y >> k;
			update(y, y+k-1, x-y, i+1);
		}else{
			int pos;
			cin >> pos;
			cout <<  get(pos) << "\n";
		}
	}

	return 0;
}