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

bool used[201][201][4][4];
int dp[201][201][4][4];
pii op[201][201][4][4];

int solve( int restA, int restB, int pA, int pB ){
    int set = pA + pB;
    if( set==5 || pA==3 || pB==3 ) return ( restA==0 && restB==0? pA-pB: -INF );
    if( used[restA][restB][pA][pB] ) return dp[restA][restB][pA][pB];

    int &r = dp[restA][restB][pA][pB] = -INF;
    pii &opt = op[restA][restB][pA][pB] = {-1,-1};
    int minPoints = (set==4? 15: 25);

    if( restA>=minPoints ){
        FOR(i,0,min(restB+1, minPoints-1)){
            int val = solve(restA-minPoints, restB-i, pA+1, pB);
            if( val!=-INF && val > r ){
                r = val;
                opt = {minPoints, i};
            }
        }
    }

    if( restB>=minPoints ){
        FOR(i,0,min(restA+1, minPoints-1)){
            int val = solve(restA-i, restB-minPoints, pA, pB+1);
            if( val!=-INF && val > r ){
                r = val;
                opt = {i,minPoints};
            }
        }
    }

    FOR(i,minPoints-1,201){
        if( restA-i-2>=0 && restB-i>=0 ){
            int val = solve(restA-i-2, restB-i, pA+1, pB);
            if( val!=-INF && val > r ){
                r = val;
                opt = {i+2,i};
            }
        }

        if( restA-i>=0 && restB-i-2>=0 ){
            int val = solve(restA-i, restB-i-2, pA, pB+1);
            if( val!=-INF && val > r ){
                r = val;
                opt = {i,i+2};
            }
        }
    }
    used[restA][restB][pA][pB] = true;
    return r;
}

int main(){
    int t; ri(t);
    while(t--){
        int a, b; rii(a,b);
        //cout << a << " "<< b << endl;
        int ans = solve(a,b,0,0);
        if(ans==-INF) printf("Impossible\n");
        else{
            pii score = op[a][b][0][0];
            vector<pii> scTot;
            int A = 0, B = 0;
            while( a>0 || b>0 ){
                a = a - score._1;
                b = b - score._2;
                if( score._1 > score._2 ) A++;
                else B++;

                scTot.pb(score);
                score = op[a][b][A][B];
            }
            printf("%d:%d\n", A, B);
            for(auto e: scTot) printf("%d:%d ", e._1, e._2);
            printf("\n");
        }
    }
    return 0;
}
/*

*/  

