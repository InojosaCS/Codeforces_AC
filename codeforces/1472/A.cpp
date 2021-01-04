#include <bits/stdc++.h> 
 
using namespace std; 

void solve(int test){
  int h, w, n;
  cin >> h >> w >> n;
  
  int64_t k = 1;
  
  while(h % 2 == 0) h /= 2, k *= 2;
  while(w % 2 == 0) w /= 2, k *= 2;
  
  if(k >= n) cout << "YES\n";
  else cout << "NO\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int32_t testCase = 1;
    cin >> testCase;

    while(testCase-->0) solve(testCase);
    
    return 0;
}	
