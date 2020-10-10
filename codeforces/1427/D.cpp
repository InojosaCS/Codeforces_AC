#include <bits/stdc++.h>
 
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	vector<int> copy = a;
	sort(copy.begin(), copy.end());
	vector<vector<int64_t>> op(n);
	int cnt = 0;
	
	for (int step = 1; step < n; step++)
	{
		int prev = step;
		int current = step + 1;
		int pp = 0, pc = 0, p1 = 0;
		
		for (int i = 0; i < n; i++)
		{
			if(a[i]==prev)  pp = i;
			if(a[i]==current)  pc = i;
			if(a[i]==1)  p1 = i;
		}
		
	
		vector<int> w;
		vector<int> x;
		vector<int> y;
		vector<int> z;
		
		//cout << "\nstep: " << step << "\n" << p1 << " " << pp << " " << pc << " *** ";
		
		// ...n+1....(n n-1 n-2..2 1)....
		if(pc < pp && pp <= p1) {
			//cout << "1\n";
			
			op[step].push_back(pc);
			op[step].push_back(pp-1-pc+1);
			
			for (int i = 0; i < pc; i++)
				x.push_back(a[i]);
			
			for (int i = pc; i < pp; i++)
				y.push_back(a[i]);
				
			for (int i = pp; i < n; i++){
				z.push_back(a[i]);
				op[step].push_back(1);
			}
			
			reverse(z.begin(), z.end());
			
		}
		
		// .....(1 2 3...n).....n+1....
		else if(pc > pp && pp >= p1){
			//cout << "2\n";
			
			for (int i = 0; i <= pp; i++){
				x.push_back(a[i]);
				op[step].push_back(1);
			}
			
			reverse(x.begin(), x.end());
			
			for (int i = pp+1; i <= pc; i++)
				y.push_back(a[i]);
				
			for (int i = pc+1; i < n; i++)
				z.push_back(a[i]);
				
			op[step].push_back(pc-(pp+1)+1);
			if(n-1-(pc+1)+1) op[step].push_back(n-1-(pc+1)+1);
			//cout << step << ": AAAwhoOooPS " << pc-(pp+1)+1 << "\n";
			//if(n-1-(pc+1)+1) cout << "whoOooPS " << n-1-(pc+1)+1 << " " << n-1 << " " << pc+1 << "\n";
		}
		
		// ....4 3 2 1 .... 5 ...
		else if(p1 >= pp && pc > p1) {
			//cout << "3\n";
			
			for (int i = 0; i < pp; i++)
				w.push_back(a[i]);
			
			for (int i = pp; i <= p1; i++)
				x.push_back(a[i]);
			
			for (int i = p1 + 1; i <= pc; i++)
				y.push_back(a[i]);
				
			for (int i = pc+1; i < n; i++)
				z.push_back(a[i]);
			
			op[step].push_back(pp);
			op[step].push_back(p1-pp+1);
			op[step].push_back(pc-(p1+1)+1);
			op[step].push_back(n-1-(pc+1)+1);
		}
		
		// .....5....1 2 3 4 ...
		else if(p1 <= pp && pc < p1) {
			//cout << "4\n";
			
			for (int i = 0; i <= pc; i++){
				x.push_back(a[i]);
				op[step].push_back(1);
			}
			
			reverse(x.begin(), x.end());
			
			for (int i = pc+1; i <= pp; i++)
				y.push_back(a[i]);
				
			for (int i = pp+1; i < n; i++)
				z.push_back(a[i]);
				
			op[step].push_back(pp-(pc+1)+1);
			op[step].push_back(n-1-(pp+1)+1);
		}
		
		int ind = 0;
		for(int f: z) a[ind++] = f;
		for(int f: y) a[ind++] = f;
		for(int f: x) a[ind++] = f;
		for(int f: w) a[ind++] = f;
		
		cnt++;
		//for (int i = 0; i < n; i++)
			//cout << a[i] << (i==n-1?"\n":" ");
	}
	
	vector<int> p = a;
	
	if(copy!=a){
		reverse(p.begin(), p.end());
	}
	
	assert(copy==p);
	
	// Printing the answer
	cout << n-1+(copy!=a)<< "\n";
	
	
	for (int i = 0; i < n; i++)
	{
		if(op[i].size() == 0) continue;
		
		int sz = 0;
		
		for (int j = 0; j < (int) op[i].size(); j++)
			if(op[i][j] > 0)
				sz++;
			
		cout << sz << " ";
		
		for (int j = 0; j < (int) op[i].size(); j++)
			if(op[i][j] > 0)
				cout << op[i][j] << " ";
			
		cout << "\n";
	}
	
	if(copy!=a){
		cout << n << " ";
		for (int i = 0; i < n; i++)
			cout << "1 ";
		cout << "\n";
	}
	
	return;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	int tt = 1;
	//cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}
