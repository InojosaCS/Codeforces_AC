#include <bits/stdc++.h>
 
using namespace std;

int main(){
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<long long> a(n), ans;
		
		for (int i = 0; i < n; i++)
			cin >> a[i];
		
		int mex = 0, cnt = 0;
		
		for(int i=n; i>0; i--){
			while(mex!=i )
			{
				vector<bool>visited(n+2,0);
				mex = 0;
				for(int j=0; j<n; j++){
					visited[a[j]]=1;
					while(visited[mex]){
						mex++;
					}
				}
				if(mex==i){
					a[mex-1]=mex;
					ans.push_back(mex-1+1);
					//cout << mex - 1 << " ";
				}else{
					a[mex]=mex;
					ans.push_back(mex+1);
					//cout << mex << " ";
				}
				cnt++;
			}
		}

		cout << cnt << "\n";
		for(auto x: ans){
			cout << x << " ";
		}
		cout << "\n";
		//for (int i = 0; i < n; i++)
			//cout << a[i] << " ";
		//cout << "\n";
	} 
	return 0;
}
