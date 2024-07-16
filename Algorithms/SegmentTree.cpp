#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct SegTree{
    int N;
    const T NEU=0;
    vector<T>tree;

    T merge(T a,T b){
        return max(a,b);
    }

    SegTree(vector<T>&a){
        N=1;
        int n=a.size();
        while(N<n) N<<=1;

        tree.assign(N<<1,NEU);
        for(int i=0;i<n;i++) tree[i+N]=a[i];
        for(int i=N-1;i>0;i--) tree[i]=merge(tree[i<<1],tree[i<<1|1]);
    }

    void update(int v,int l,int r,int id,T x){
        if(l>id || id>=r) return;
        if(r-l==1){
            tree[v]=x;
            return;
        }

        int mid=(l+r)>>1;
        update(v<<1,l,mid,id,x);
        update(v<<1|1,mid,r,id,x);

        tree[v]=merge(tree[v<<1],tree[v<<1|1]);
    }

    void update(int id,T x){
        return update(1,0,N,id,x);
    }

    T get(int v,int l,int r,int ql,int qr){
        if(l>=qr || ql>=r) return NEU;
        if(l>=ql && qr>=r) return tree[v];

        int mid=(l+r)>>1;
        int a=get(v<<1,l,mid,ql,qr);
        int b=get(v<<1|1,mid,r,ql,qr);
        return merge(a,b);
    }

    T get(int l,int r){
        return get(1,0,N,l,r);
    }
};

signed main(){
    // your code here
    // vector<int>a={2,3,5,1,6};
    // SegTree S(a);
    // cout<<S.get(1,3);
}