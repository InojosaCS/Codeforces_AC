/*
ID: cristia35
TASK: cf
LANG: C++
*/

#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <stdio.h>	
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
typedef vector<ii> vii;

#define solve imAwesome
#define for0(i,n) for(int i=0; i<(int)n; i++)
#define forn(i,n) for(int i=1; i<=(int)n; i++)
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define all(x) x.begin(),x.end()
#define endl cout << "\n";
#define debug cout << "Aqui\n";
#define deb(i) cout << "Aqui " << (ll) i << "\n";
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	//ifstream cin ("subset.in");
	//ofstream cout ("subset.out");

	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		int a[n+1][n+1];
		
		for (int i = 0; i <=n; i++)
		{
			for0(j,n+1){
				if(j == n || i==n) a[i][j]=1;
				else a[i][j]=0;
			}
		}
		
		string ans = "YES\n";
		
		for (int i = 0; i < n; i++)
		{
			for0(j,n){
				char p;
				cin >> p;
				a[i][j]=p-'0';
			}
		}
		
		for (int i = 0; i < n; i++)
		{
			for0(j,n){
				if(a[i][j]	&& !a[i][j+1] && 	!a[i+1][j])
					ans = "NO\n";
			}
		}
		cout << ans;
	}
	
	return 0;

}
