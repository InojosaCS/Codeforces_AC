#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
 
#define solve imAwesome
#define for0(i,n) for(int i=0; i<(int)n; i++)
#define forn(i,n) for(int i=1; i<=(int)n; i++)
#define pb push_back
#define f first
#define s second
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define all(x) x.begin(),x.end()
#define sz(s) (ll) s.size()
#define endl cout << "\n";
#define deb(i) cout << "Aqui " << (ld) i << "\n";
//#define int long long
 
ll n, m, aux, current,sz;	
vll st((1<<18),0);

void update(ll pos, ll val){
	
	pos = pos+sz-1;
	st[pos] = val;
	int helper=0;
	
	while(pos){
		pos/=2;
		if(helper%2==0)
			st[pos] = st[pos*2] | st[pos*2+1];
		else
			st[pos] = st[pos*2] ^ st[pos*2+1];
		helper++;
	}
}

int32_t main(){
	
	cin >> n >> m;
	aux = sz = (1 << n);
	current = sz-1;
	
	for(int i=sz; i<2*sz; i++)
		cin >> st[i];
	
	//for(int i=sz; i<2*sz; i++)
		//cout << st[i] << " ";
		
	//cout << "\n";
	
	for (int i = 0; i < n; i++)
	{
		aux /= 2;
		if(i%2==0){
			for( int j=0; j<aux; j++){
				st[current] = st[current*2] | st[current*2+1]; 
		//		cout << st[current] << " ";
				current--;
			}
		}else{
			for( int j=0; j<aux; j++){
				st[current] = st[current*2] ^ st[current*2+1]; 
	//			cout << st[current] << " ";
				current--;
			}
		}
	}
	
	while(m--){
		ll pos,val;
		cin >> pos >> val;
		update(pos,val);
		//aux = sz;
		//current = sz-1;
		
		//for (int i = 0; i < n; i++)
		//{
			//aux /= 2;
			//if(i%2==0){
				//for( int j=0; j<aux; j++){
					//cout << st[current] << " ";
					//current--;
				//}
			//}else{
				//for( int j=0; j<aux; j++){
					//cout << st[current] << " ";
					//current--;
				//}
			//}
			//cout << "\n";
		//}
		
		cout << st[1] << "\n";
	}
	
	return 0;
	
}
