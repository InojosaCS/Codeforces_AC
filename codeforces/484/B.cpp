#include <bits/stdc++.h> 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")

using namespace std; 

struct segtree {
    vector<int> tree;
    int sz = 1;
    int identity = 0;
    
    void init(int n){
        while(sz < n){
            sz *= 2;
        }
        tree.assign(2*sz, identity);
    }
    
    int merge(int x, int y){
        return max(x, y);
    }
    
    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            tree[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m) set(i, v, 2 * x + 1, lx, m);
        else set(i, v, 2 * x + 2, m, rx);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }
    
    void set(int i, int v){
        set(i, v, 0, 0, sz);
    }
    
    int get(int l, int r, int x, int lx, int rx){
        if(l <= lx && rx <= r) return tree[x];
        if(rx <= l || lx >= r) return identity; 
        int m = (lx + rx) / 2;
        int e1 = get(l, r, 2 * x + 1, lx, m);
        int e2 = get(l, r, 2 * x + 2, m, rx);
        return merge(e1, e2);
    }
    
    int get(int l, int r){
        return get(l, r, 0, 0, sz);
    }
};

void solve(){
    int n, fff = 0;
    cin >> n;
    set<int> s;
    
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    
    n = s.size();
    vector<int> a(n);
    for(int x: s) a[fff++] = x;
    
    int mx = a[n-1] + 1, ans = 0;
    segtree st;
    st.init(mx+9);
    
    for (int i = 0; i < n; i++)
    {
        st.set(a[i], a[i]);
    }
    
    reverse(a.begin(), a.end());
    
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        if(ans >= x-1) break;
        for (int j = 2 * x; j <= mx; j += x)
        {
            int up = st.get(j - x, j);
            ans = max(ans, up - (j - x));
        }
        int lb = (mx / x) * x;
        int up = st.get(lb, mx + 1);
        ans = max(ans, up - lb);
    }
    
    cout << ans << "\n";
    
    //reverse(a.begin(), a.end());
    //ans = 0;
    
    //for (int i = 0; i < n; i++)
    //{
        //for (int j = i+1; j < n; j++)
        //{
            //ans = max(ans, a[i] % a[j]);
        //}
        
    //}
    //cout << ans << "\n";
}
    
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    
	int32_t tt = 1;
	//cin >> tt;

	while(tt-->0) solve();
	
	return 0;
}
