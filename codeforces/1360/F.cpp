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
		ll a,b;
		cin >> a >> b;
		vector<string> words(a);
		vector<string> ans;
		
		for (int i = 0; i < a; i++) cin >> words[i];
		ans.pb(words[0]);
		
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < a; j++)
			{
				ll diff=0ll;
				for (int k = 0; k < b; k++)
					if(words[i][k]!=words[j][k]) diff++;
				
				if(diff==2){
					for (int k = 0; k < b; k++)
						if(words[i][k]!=words[j][k]){
							string as = words[i];
							as[k]=words[j][k];
							ans.pb(as);
						}
				}
				if(diff<=1) ans.pb(words[j]);	
			}
		}
		
		bool helper = true;
		int sz = ans.size();
		
		for (int i = 0; i < sz; i++)
		{
			helper = true;
			
			for (int j = 0; j < a; j++)
			{
				ll diff=0ll;
				for (int k = 0; k < b; k++)
					if(ans[i][k]!=words[j][k]) diff++;
				
				if(diff>1)  helper = false;	
			}
			
			if(helper) 
			{
				cout << ans[i] << "\n";
				break;
			}
		}
		
		if(!helper) cout << "-1\n";
			
	}
	
	return 0;

}
