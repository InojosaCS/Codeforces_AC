#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define debug(x) cout << (#x) << " is " << (x) << endl;
#define ll long long
  
pair<long double, long double> lineLineIntersection(pair<long double, long double> A, pair<long double, long double> B, 
	long double a2, long double b2, long double c2) 
{ 
    // Line AB represented as a1x + b1y = c1 
    long double a1 = B.second - A.second; 
    long double b1 = A.first - B.first; 
    long double c1 = a1*(A.first) + b1*(A.second); 
  
    // Line CD represented as a2x + b2y = c2 
    // long double a2 = D.second - C.second; 
    // long double b2 = C.first - D.first; 
    // long double c2 = a2*(C.first)+ b2*(C.second); 
  
    long double determinant = a1*b2 - a2*b1; 
  
    if (determinant == 0) 
    { 
        // The lines are parallel. This is simplified 
        // by returning a pair of FLT_MAX 
        return {-111111111,-111111111}; 
    } 
    else
    { 
        long double x = (b2*c1 - b1*c2)/determinant; 
        long double y = (a1*c2 - a2*c1)/determinant; 
        return {x,y}; 
    } 
} 

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.precision(20);
 
	long double x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		long double a2,b2,c2,l,r;
		cin >> a2 >> b2 >> c2;
		tie(l,r) = lineLineIntersection({x1,y1}, {x2,y2}, a2, b2, -c2);
		// cout << l << " " << r << "\n";
		if(min(x1,x2)<=l && l<=max(x1,x2) && min(y1,y2)<=r && r<=max(y1,y2)){
			cnt++;
		}
	}
	cout << cnt << "\n";
	return 0;
}