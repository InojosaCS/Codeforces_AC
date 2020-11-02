#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <string.h>
#include <math.h>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define ri(a) scanf("%d",&a)
#define rii(a,b) ri(a),ri(b)
#define riii(a,b,c) rii(a,b),ri(c)
#define lri(a) scanf("%lld",&a)
#define lrii(a,b) lri(a),lri(b)
#define lriii(a,b,c) lrii(a,b),lri(c)
#define pb push_back
#define _1 first
#define _2 second
#define ALL(s) s.begin(),s.end()
#define SZ(x) int((x).size())

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 998244353; //1e9+7;
const int alphabet = 26;
const double PI = 3.1415926535;
const int MAXINT = 1e5+1;

int main(){
    int t; ri(t);
    while(t--){
        int k; ri(k); vector<int> a(7);
        int cnt = 0;
        FOR(i,0,7) ri(a[i]), cnt += a[i];

        int ans = INF;
        FOR(i,0,7){
            int vuelta = k/cnt-(k%cnt==0);
            int need = k - vuelta*cnt;
            int ansTemp = 7*vuelta;
            FOR(j,0,7){
                if(need==0) break;
                need -= a[(i+j)%7];
                ansTemp++;
            }
            ans = min( ans, ansTemp );
        }
        printf("%d\n", ans);
    }

    return 0;
}
/*
6
75 0
90 90
20 0
0 75
78 50
80 100

*/  

