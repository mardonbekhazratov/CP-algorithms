#include<bits/stdc++.h>
using namespace std;

struct mergeSortTree{
    int N,n;
    vector<vector<int>>tree;

    void build(vector<int>&a,int v,int l,int r){
        if(r-l==1){
            if(l<n) tree[v]={a[l]};
            return;
        }
        int mid=(l+r)/2;

        build(a,v<<1,l,mid);
        build(a,v<<1|1,mid,r);

        merge(all(tree[v<<1]),all(tree[v<<1|1]),back_inserter(tree[v]));
    }

    mergeSortTree(vector<int>&a){
        n=a.size();
        N=1;
        while(N<n) N<<=1;

        tree.resize(2*N);
        build(a,1,0,N);
    }

    int get(int v,int l,int r,int ql,int qr,int x){
        if(l>=qr || ql>=r) return 0;
        if(l>=ql && qr>=r){
            return tree[v].size()-(upper_bound(all(tree[v]),2*x)-tree[v].begin());
        }

        int mid=(l+r)/2;
        return get(v<<1,l,mid,ql,qr,x)+get(v<<1|1,mid,r,ql,qr,x);
    }

    int get(int l,int r,int x){
        return get(1,0,N,l,r,x);
    }
};

signed main(){
    int n;
    cin>>n;
}