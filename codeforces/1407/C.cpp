#include <bits/stdc++.h>
 
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 

	int n;
	cin >> n;

	std::vector<int> v(n,-1);
	int l = 1, r = 2, a, b;
	std::vector<bool> visited(n + 7, false);

	for (int i = 2; i <= n; ++i)
	{
		r = i;
		cout << "? " << l << " " << r << "\n";
		cout.flush();
		cin >> a;
		cout << "? " << r << " " << l << "\n";
		cout.flush();
		cin >> b;
		assert(v[l-1] == -1);
		assert(v[r-1] == -1);
		if(a > b){
			v[l-1] = a;
			l = r;
			visited[a] = true;
		} else {
			v[r-1] = b;
			visited[b] = true;
		}
	}
	
	int look = -1;

	for (int i = 0; i < n && look == -1; ++i)
		if(!visited[i+1])
			look = i + 1;
	
	for (int i = 0; i < n; ++i){
		if(v[i] == -1){
			v[i] = look;
			break;
		}
	}
	
	cout << "! ";
	for (int i = 0; i < int(v.size()); ++i)
		cout << v[i] << " ";
	
	cout << "\n";
	return 0;
}
