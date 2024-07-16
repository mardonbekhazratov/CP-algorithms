#include<bits/stdc++.h>
using namespace std;

int n,q;
vector<vector<int>>v;
vector<int>depth,heavy,up,top,id,p,dp;

struct SegTree{
    int N;
    const int NEU=0;
    vector<int>tree;

    int merge(int a,int b){
        return max(a,b);
    }

    void build(vector<int>&a){
        N=1;
        int n=a.size();
        while(N<n) N<<=1;

        tree.assign(N<<1,NEU);
        for(int i=0;i<n;i++) tree[i+N]=a[i];
        for(int i=N-1;i>0;i--) tree[i]=merge(tree[i<<1],tree[i<<1|1]);
    }

    void update(int v,int l,int r,int id,int x){
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

    void update(int id,int x){
        return update(1,0,N,id,x);
    }

    int get(int v,int l,int r,int ql,int qr){
        if(l>=qr || ql>=r) return NEU;
        if(l>=ql && qr>=r) return tree[v];

        int mid=(l+r)>>1;
        int a=get(v<<1,l,mid,ql,qr);
        int b=get(v<<1|1,mid,r,ql,qr);
        return merge(a,b);
    }

    int get(int l,int r){
        return get(1,0,N,l,r);
    }
};

SegTree S;

int dfs(int x,int parent,int c){
    int mx=0;
    depth[x]=c;
    up[x]=parent;
    dp[x]=1;
    for(int z:v[x]){
        if(z!=parent){
            dp[x]+=dfs(z,x,c+1);
            if(dp[z]>mx){
                mx=dp[z];
                heavy[x]=z;
            }
        }
    }
    return dp[x];
}


void go(int x,int parent,int y){
    if(y!=-1) top[x]=top[y];
    else top[x]=x;
    p.push_back(x);
    id[x]=p.size()-1;
    if(heavy[x]) go(heavy[x],x,x);
    for(int z:v[x]){
        if(z!=parent && z!=heavy[x]) go(z,x,-1);
    }
}

int get(int a,int b){
    int x=top[a];
    int y=top[b];
    if(x==y){
        if(depth[a]>depth[b]) swap(a,b);
        return S.get(id[a],id[b]+1);
    }
    if(depth[x]>depth[y]){
        return max(S.get(id[x],id[a]+1),get(up[x],b));
    }
    return max(S.get(id[y],id[b]+1),get(a,up[y]));
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>q;
    vector<int>val(n+1);
    v.resize(n+1);
    id.resize(n+1);
    dp.resize(n+1);
    top.resize(n+1);
    heavy.resize(n+1);
    depth.resize(n+1);
    up.resize(n+1);
    for(int i=1;i<=n;i++) cin>>val[i];
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,1,0);
    go(1,-1,-1);
    vector<int>gg(n);
    for(int i=1;i<=n;i++) gg[id[i]]=val[i];
    S.build(gg);
    while(q--){
        int ch,a,b;
        cin>>ch>>a>>b;
        if(ch==1){
            S.update(id[a],b);
        }
        else{
            cout<<get(a,b)<<" ";
        }
    }
}