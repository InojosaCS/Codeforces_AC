#include <bits/stdc++.h> 
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")

using namespace std; 

struct segtree {
    
    int size;
    vector<int64_t> mins;
    
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        mins.assign(2*size, 0LL);
    }    
    
    void build(vector<int> &a, int x, int lx, int rx){
        if(rx - lx == 1) {
            if(lx < (int) a.size()) mins[x] = a[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        mins[x] = min(mins[2 * x + 1], mins[2 * x + 2]);
    }
    
    void build(vector<int> &a){
            build(a, 0, 0, size);
    }
    
    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            mins[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }
        mins[x] = min(mins[2 * x + 2], mins[2 * x + 1]);
    }
    
    void set(int i, int v){
        set(i, v, 0, 0, size);
    }
    
    int64_t minimum(int l, int r, int x, int lx, int rx){
        if(lx >= r || rx <= l) return INT_MAX;
        if(l <= lx && rx <= r) return mins[x];
        int m = (lx + rx) / 2; 
        int64_t s1 = minimum(l, r, 2 * x + 1, lx, m);
        int64_t s2 = minimum(l, r, 2 * x + 2, m, rx);
        return min(s1, s2);
    }
    
    
    int64_t minimum(int l, int r){
        return minimum(l, r, 0, 0, size);
    }
    
};

void solve(){
    //cout << "TEST ***********************\n";
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> mxl(n);
    vector<int> mxr(n);
    map<int,set<int>> g;
    int mx = -1;
    
    for (int i = 0; i < n; i++)
    {
	cin >> a[i];
	g[a[i]].insert(i);
	mxl[i] = mx = max(mx, a[i]);
    }
    
    mx = -1;
    
    for (int i = n-1; i >= 0; i--)
    {
	mxr[i] = mx = max(a[i], mx);
    }
    
    segtree st;
    st.init(n);
    st.build(a);
    
    for (int i = 0; i+2 < n; i++)
    {
	int l = i+2;
	int r = n;
	int x = mxl[i];
	int pos = -1;
	int right = -5, left = -5;
	
	while(l < r){
	    int mid = (l+r) / 2;
	    if(mxr[mid] >= x){
		if(mxr[mid] == x) right = mid;
		l = mid + 1;
	    } else {
		r = mid;
	    }
	}
	
	l = i+2; r = n;
	
	while(l < r){
	    int mid = (l+r) / 2;
	    if(mxr[mid] > x){
		l = mid + 1;
	    } else {
		if(mxr[mid] == x) left = mid;
		r = mid;
	    }
	}
	
	if(g[x].lower_bound(i+1) != g[x].end()) pos = *g[x].lower_bound(i+1);
	
	if(pos >= right) continue;
	int mn = st.minimum(i+1, left);
	
	if(right > left && a[left] == x && st.minimum(i+1, left+1) == x){
	    left++;
	    mn = x;
	}
	
	if(mn == x && mxr[right] == mn){
	    //cout << left << " " << right << "\n";
	    cout << "YES\n";
	    pos = left - 1;
	    int aa = i+1;
	    int b = pos - i;
	    int c = n - pos - 1;
	    //cout << pos << "\n";
	    cout << aa << " " << b << " " << c << "\n";
	    return;
	}
    }
    cout << "NO\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int32_t tt = 1;
    cin >> tt;

    while(tt-->0) solve();
    
    return 0;
}	
