#include <bits/stdc++.h>
 
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (__int64) x.size()
#define debug(x) cout << (#x) << " is " << x << "\n";

__int64 solve(){
	int nr, ng, nb,a;
	cin >> nr >> ng >> nb;
	vector<__int64> red(nr,0), green(ng,0), blue(nb,0), redless(nr,0), greenless(ng,0), blueless(nb,0);
	
	for (int i = 0; i < nr; ++i)
	{
		cin >> a;
		red[i] = a;
		redless[i] = -a;
	}

	for (int i = 0; i < ng; ++i)
	{
		cin >> a;
		green[i] = a;
		greenless[i] = -a;
	}

	for (int i = 0; i < nb; ++i)
	{
		cin >> a;
		blue[i] = a;
		blueless[i] = -a;
	}

	sort(all(red));sort(all(redless));
	sort(all(green));sort(all(greenless));
	sort(all(blue));sort(all(blueless));
	__int64 mn = (__int64)(1e18*3+7);

	for(__int64 m: red){
		auto it1 = lower_bound(all(green), m); 
		auto it2 = lower_bound(all(blueless), -m);
		int posx = it1 - green.begin();
		int posy = it2 - blueless.begin();
		long long x = (posx==ng) ? green[ng-1] : green[posx];
		long long y = (posy==nb) ? blue[0] : -blueless[posy];
	
		__int64 current = (m-x)*(m-x)+(m-y)*(m-y)+(x-y)*(x-y);
		mn = min(mn, current);
		// cout << m << " " << x << " " << y << "\n";
	}

	for(__int64 m: red){
		auto it1 = lower_bound(all(blue), m); 
		auto it2 = lower_bound(all(greenless), -m);
		int posx = it1 - blue.begin();
		int posy = it2 - greenless.begin();
		long long x = (posx==nb) ? blue[nb-1] : blue[posx];
		long long y = (posy==ng) ? green[0] : -greenless[posy];
	
		__int64 current = (m-x)*(m-x)+(m-y)*(m-y)+(x-y)*(x-y);
		mn = min(mn, current);
		// cout << m << " " << x << " " << y << "\n";
	}
	for(__int64 m: green){
		auto it1 = lower_bound(all(red), m); 
		auto it2 = lower_bound(all(blueless), -m);
		int posx = it1 - red.begin();
		int posy = it2 - blueless.begin();
		long long x = (posx==nr) ? red[nr-1] : red[posx];
		long long y = (posy==nb) ? blue[0] : -blueless[posy];
	
		__int64 current = (m-x)*(m-x)+(m-y)*(m-y)+(x-y)*(x-y);
		mn = min(mn, current);
		// cout << m << " " << x << " " << y << "\n";
	}

	for(__int64 m: green){
		auto it1 = lower_bound(all(blue), m); 
		auto it2 = lower_bound(all(redless), -m);
		int posx = it1 - blue.begin();
		int posy = it2 - redless.begin();
		long long x = (posx==nb) ? blue[nb-1] : blue[posx];
		long long y = (posy==nr) ? red[0] : -redless[posy];
	
		__int64 current = (m-x)*(m-x)+(m-y)*(m-y)+(x-y)*(x-y);
		mn = min(mn, current);
		// cout << m << " " << x << " " << y << "\n";
	}

	for(__int64 m: blue){
		auto it1 = lower_bound(all(red), m); 
		auto it2 = lower_bound(all(greenless), -m);
		int posx = it1 - red.begin();
		int posy = it2 - greenless.begin();
		long long x = (posx==nr) ? red[nr-1] : red[posx];
		long long y = (posy==ng) ? green[0] : -greenless[posy];
	
		__int64 current = (m-x)*(m-x)+(m-y)*(m-y)+(x-y)*(x-y);
		mn = min(mn, current);
		// cout << m << " " << x << " " << y << "\n";
	}

	for(__int64 m: blue){
		auto it1 = lower_bound(all(green), m); 
		auto it2 = lower_bound(all(redless), -m);
		int posx = it1 - green.begin();
		int posy = it2 - redless.begin();
		long long x = (posx==ng) ? green[ng-1] : green[posx];
		long long y = (posy==nr) ? red[0] : -redless[posy];
	
		__int64 current = (m-x)*(m-x)+(m-y)*(m-y)+(x-y)*(x-y);
		mn = min(mn, current);
		// cout << m << " " << x << " " << y << "\n";
	}

	return mn;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.precision(20);

	int t;
	cin >> t;
	while(t--){
		cout << solve() << "\n";
	}
	return 0;
}
