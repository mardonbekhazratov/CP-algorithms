#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct SegTree{
    struct node{
        T pref,sum;
        node(T sum,T pref) : sum(sum),pref(pref){}
        node(T x = 0) : sum(x),pref(x<0 ? 0 : x){}
        friend node operator+(const node&a,const node&b){
            return {a.sum+b.sum,max(a.pref,a.sum+b.pref)};
        }
    };

    int N;
    vector<node>tree;
    SegTree(vector<T>&a){
        int n=(int)a.size();
        N=1;
        while(N<n) N<<=1;

        tree.resize(2*N);
        for(int i=0;i<N;i++){
            if(i<n) tree[i+N]=node(a[i]);
            else tree[i+N]=node();
        }
        for(int i=N-1;i>0;i--) tree[i]=tree[i<<1]+tree[i<<1|1];
    }

    void update(int v,int l,int r,int id,T x){
        if(r-l==1){
            tree[v]=node(x);
            return;
        }
        int mid=(l+r)/2;
        if(id<mid) update(v<<1,l,mid,id,x);
        else update(v<<1|1,mid,r,id,x);

        tree[v]=tree[v<<1]+tree[v<<1|1];
    }

    void update(int id,T x){
        return update(1,0,N,id,x);
    }

    node get(int v,int l,int r,int ql,int qr){
        if(ql>=r || l>=qr) return 0;
        if(l>=ql && qr>=r) return tree[v];

        int mid=(l+r)/2;

        node a=get(v<<1,l,mid,ql,qr);
        node b=get(v<<1|1,mid,r,ql,qr);

        return a+b;
    }

    T get(int l,int r){
        return get(1,0,N,l,r).pref;
    }
};

signed main(){
    int n;
    cin>>n;
    int q;
    cin>>q;
    vector<long long>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    SegTree S(a);
    while(q--){
        int ch,l,r;
        cin>>ch>>l>>r;
        --l;
        if(ch&1){
            S.update(l,r);
        }
        else{
            cout<<S.get(l,r)<<'\n';
        }
    }
}