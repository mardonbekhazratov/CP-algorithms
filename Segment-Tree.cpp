#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
using ll = long long;
const int INF = 1e9;

int n,N;
vector<ll> tree;

void build(vector<int>& a){
    n = a.size();
    
    N = 1;
    while(N < n) N <<= 1;

    tree.resize(2*N);

    for(int i = 0; i < n; ++i) tree[i+N] = a[i];
    for(int i = n; i < N; ++i) tree[i+N] = 0;
    for(int i = N-1; i > 0; --i) tree[i] = tree[i<<1]+tree[i<<1|1];
}

void update(int v, int l, int r, int idx, int x){ // [l,r)
    if(l > idx || idx >= r) return;
    
    if(r-l == 1) {
        tree[v] = x;
        return;
    }

    int mid = (l+r)>>1;
    update(v<<1  ,l,mid,idx,x);
    update(v<<1|1,mid,r,idx,x);

    tree[v] = tree[v<<1]+tree[v<<1|1];
}

void update(int idx, int v){
    update(1,0,N,idx,v);
}

ll get(int v, int l, int r, int ql, int qr){ // [l,r)
    if(l >= qr || ql >= r) return 0;
    if(l >= ql && qr >= r) return tree[v];

    int mid = (l+r)>>1;
    return get(v<<1,l,mid,ql,qr)+get(v<<1|1,mid,r,ql,qr);
}

ll get(int l, int r){
    return get(1,0,N,l,r);
}

int main(){
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt","w",stderr);
    #endif

    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    build(a);

    int m; cin >> m;
    while(m--){
        string s; cin >> s;
        if(s[0] == 's'){
            int l,r; cin >> l >> r;
            cout << get(l-1,r) << " ";
        } else {
            int idx,v; cin >> idx >> v;
            update(idx-1,v);
        }
    }
}
