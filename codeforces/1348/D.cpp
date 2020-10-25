#include <bits/stdc++.h>

using namespace std;

void solve() {
    int64_t n;
    cin >> n;
    
    vector<int64_t> aux;
    int64_t sum = 0LL, helper = 1LL;
    
    while(sum + helper < n){
        aux.push_back(helper);
        sum += helper;
        helper *= 2LL;
    }
    
    aux.push_back(n-sum);
    sort(aux.begin(), aux.end());
    
    cout << (int) aux.size() - 1 << "\n";
    
    for (int i = 0; i+1 < (int) aux.size(); i++)
        cout << aux[i+1] - aux[i] << (i+1==(int)aux.size()-1 ? "\n" : " ");
    
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int32_t tt = 1;
    cin >> tt;

    while(tt-->0) solve();

    return 0;
}
